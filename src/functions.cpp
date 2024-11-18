#include "../include/functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool parseProduct(const string& line, Product& product) {
    istringstream iss(line);
    if (iss >> product.name >> product.shop >> product.price >> product.quantity >> product.unit) {
        return true;
    }
    return false;
}

void printProduct(const Product& product) {
    cout << product.name << " "
         << product.shop << " "
         << product.price << " "
         << product.quantity << " "
         << product.unit << "\n";
}

void viewAllProducts(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    Product product;
    string line;
    while (getline(file, line)) {
        if (parseProduct(line, product)) {
            printProduct(product);
        }
    }
    file.close();
}

void addProduct(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    Product product;
    cout << "Введіть назву товару: ";
    cin >> product.name;
    cout << "Введіть назву магазину: ";
    cin >> product.shop;
    cout << "Введіть ціну товару: ";
    cin >> product.price;
    cout << "Введіть кількість товару: ";
    cin >> product.quantity;
    cout << "Введіть одиницю виміру: ";
    cin >> product.unit;

    file << product.name << " "
         << product.shop << " "
         << product.price << " "
         << product.quantity << " "
         << product.unit << "\n";

    file.close();
    cout << "Товар додано успішно!" << endl;
}

void searchByShop(const string& filename, const string& shopName) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    Product product;
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (parseProduct(line, product) && product.shop == shopName) {
            printProduct(product);
            found = true;
        }
    }

    if (!found) {
        cout << "Товари в магазині " << shopName << " не знайдено." << endl;
    }

    file.close();
}

void searchByPriceRange(const string& filename, double minPrice, double maxPrice) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    Product product;
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (parseProduct(line, product) && product.price >= minPrice && product.price <= maxPrice) {
            printProduct(product);
            found = true;
        }
    }

    if (!found) {
        cout << "Товарів у заданому діапазоні не знайдено." << endl;
    }

    file.close();
}
