# E-Commerce Product Web Scraper (C++)

## Overview

This project is a simple web scraper built in C++ that extracts product information from an online e-commerce website and stores the data in a CSV file.

The scraper collects:

* Product Name
* Product Price
* Product Rating

The extracted data is saved in a structured CSV format for further analysis or processing.

## Features

* Fetches webpage data using libcurl
* Extracts product details using Regular Expressions (Regex)
* Stores data in CSV format
* Simple and lightweight implementation in C++
* Demonstrates web scraping and file handling concepts

## Technologies Used

* C++
* libcurl
* Regular Expressions (regex)
* File Handling

## Project Structure

```text
task4SC/
│
├── scraper.cpp
├── products.csv
└── README.md
```

## How to Compile

```bash
clang++ scraper.cpp -o scraper -lcurl -std=c++11
```

## How to Run

```bash
./scraper
```

## Output

After running the program, a file named `products.csv` is generated containing product information.

Example:

```csv
Name,Price,Rating
A Light in the Attic,51.77,Three
Tipping the Velvet,53.74,One
Soumission,50.10,One
```

## Learning Outcomes

Through this project, I learned:

* Web scraping fundamentals
* HTTP requests using libcurl
* Data extraction using regex
* CSV file generation in C++
* File handling and data storage techniques

## Author

Sanskriti
SkillCraft Technology Internship Project
