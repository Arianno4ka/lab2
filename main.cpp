#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char choice;

    while (true) {
        // Выводим опции меню

        std::cout << "===== Меню =====" << std::endl;
        std::cout << "1. Добавить выступление" << std::endl;
        std::cout << "2. Посмотреть выступления" << std::endl;
        std::cout << "3. Удалить выступление" << std::endl;
        std::cout << "4. Добавить администратора" << std::endl;
        std::cout << "5. Посмотреть администратора" << std::endl;
        std::cout << "6. Удалить администратора" << std::endl;
        std::cout << "7. Добавить спикера" << std::endl;
        std::cout << "8. Посмотреть спикера" << std::endl;
        std::cout << "9. Удалить спикера" << std::endl;
        std::cout << "l Загрузить" << std::endl;
        std::cout << "s Сохранить" << std::endl;
        std::cout << "0. Выйти из программы" << std::endl;

        // Запрашиваем выбор пользователя

        std::cout << "Введите номер выбранной опции: ";

        std::cin >> choice;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Обрабатываем выбор пользователя
        switch (choice) {

        case '1': {
            
            break;
        }
        case '2':
            
            break;
        case '3': {
            
            break;
        }
        case '4': {
           
            break;
        }
        case '5':
            
            break;
        case '6': {
            
            break;
        }
        case '7': {
           
            break;

        }
        case '8':
            
            break;
        case '9': {
            
            break;
        }
        case 's': {
           
            break;
        }
        case 'l': {
            
            break;
        }
        case '0':
            std::cout << "Программа завершена." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор." << std::endl;
            break;
        }
    }
}
