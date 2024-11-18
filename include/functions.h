#pragma once
#include "structures.h"
using namespace std;

bool parseProduct(const string& line, Product& product);
void printProduct(const Product& product);
void viewAllProducts(const string& filename);
void addProduct(const string& filename);
void searchByShop(const string& filename, const string& shopName);
void searchByPriceRange(const string& filename, double minPrice, double maxPrice);
