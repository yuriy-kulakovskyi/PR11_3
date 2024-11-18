#include <iostream>
#include "../include/functions.h"
using namespace std;

int main() {
    string filename;
    cout << "Введіть ім'я файлу з товарами: ";
    cin >> filename;

    int option;
    do {
        cout << "\nМеню:\n";
        cout << "1. Переглянути список товарів\n";
        cout << "2. Додати новий товар\n";
        cout << "3. Вивести товари з вказаного магазину\n";
        cout << "4. Вивести товари у заданому ціновому діапазоні\n";
        cout << "5. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> option;

        switch (option) {
            case 1:
                viewAllProducts(filename);
            break;
            case 2:
                addProduct(filename);
            break;
            case 3: {
                string shopName;
                cout << "Введіть назву магазину: ";
                cin >> shopName;
                searchByShop(filename, shopName);
                break;
            }
            case 4: {
                double minPrice, maxPrice;
                cout << "Введіть мінімальну ціну: ";
                cin >> minPrice;
                cout << "Введіть максимальну ціну: ";
                cin >> maxPrice;
                searchByPriceRange(filename, minPrice, maxPrice);
                break;
            }
            case 5:
                cout << "Вихід з програми." << endl;
            break;
            default:
                cout << "Невірна опція. Спробуйте ще раз." << endl;
        }

    } while (option != 5);

    return 0;
}
