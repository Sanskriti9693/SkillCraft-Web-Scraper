#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <curl/curl.h>

using namespace std;

struct Product {
    string name;
    string price;
    string rating;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

string fetchHTML(const string& url) {
    CURL* curl;
    CURLcode res;
    string html;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "Failed to fetch page: "
                 << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    return html;
}

int main() {

    string url = "https://books.toscrape.com/";
    string html = fetchHTML(url);

    vector<string> names;
    vector<string> prices;
    vector<string> ratings;

    regex nameRegex("title=\"([^\"]+)\"");
    regex priceRegex("<p class=\"price_color\">£([0-9\\.]+)</p>");
    regex ratingRegex("<p class=\"star-rating ([A-Za-z]+)");

    sregex_iterator end;

    for (sregex_iterator i(html.begin(), html.end(), nameRegex); i != end; ++i)
        names.push_back((*i)[1]);

    for (sregex_iterator i(html.begin(), html.end(), priceRegex); i != end; ++i)
        prices.push_back((*i)[1]);

    for (sregex_iterator i(html.begin(), html.end(), ratingRegex); i != end; ++i)
        ratings.push_back((*i)[1]);

    ofstream file("products.csv");

    file << "Name,Price,Rating\n";

    size_t n = min(names.size(), min(prices.size(), ratings.size()));

    for (size_t i = 0; i < n; i++) {
        file << "\"" << names[i] << "\","
             << prices[i] << ","
             << ratings[i] << "\n";
    }

    file.close();

    cout << "Data saved to products.csv" << endl;

    return 0;
}