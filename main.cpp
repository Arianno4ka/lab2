#include "note.h"

#include <Windows.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;
void find_change(vector <note*> notes) {
    string name;
    cout << "Введите фамилию для поиска и изменения: ";
    cin >> name;
    auto it = find_if(notes.begin(), notes.end(),
        [name](const note* n) {
            return n->getLastName() == name;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
        std::cout << "Выберите, что вы хотите изменить:" << std::endl;
        std::cout << "1. Имя" << std::endl;
        std::cout << "2. Фамилия" << std::endl;
        std::cout << "3. Номер телефона" << std::endl;
        std::cout << "4. Дата рождения" << std::endl;

        int option;
        std::cout << "Введите номер выбранной опции: ";
        std::cin >> option;
        std::cin.ignore(32767, '\n');


        if (option == 1) {
            std::string newName;
            std::cout << "Введите новое имя: ";
            std::cin >> newName;
            (*it)->setFirstName(newName);
        }
        if (option == 2) {
            std::string newLastName;
            std::cout << "Введите новую фамилию: ";
            std::cin >> newLastName;
            (*it)->setLastName(newLastName);

        }
        if (option == 3) {
            std::string newPhoneNumber;
            std::cout << "Введите новый номер телефона: ";
            std::cin >> newPhoneNumber;
            (*it)->setPhoneNumber(newPhoneNumber);

        }
        if (option == 4) {
            int newBirthDate[3];
            std::cout << "Введите новую дату рождения (день месяц год): ";
            for (int i = 0; i < 3; ++i) {
                std::cin >> newBirthDate[i];
            }
            (*it)->setBirthDate(newBirthDate);

        }
        else {
            cout << "Неверный выбор" << endl;
        }
    }
}
void find_delete(vector <note*> notes) {
    string searchLastName;
    std::cout << "Введите фамилию для поиска: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
        delete* it;  // Освобождаем память
        notes.erase(it);  // Удаляем указатель из вектора
        std::cout << "Запись удалена." << std::endl;
    }
    else {
        std::cout << "Запись не найдена." << std::endl;
    }
}
void find_lastname(vector <note*> notes) {
    string searchLastName;
    std::cout << "Введите фамилию для поиска: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
    }
    else {
        std::cout << "Запись не найдена." << std::endl;
    }
}
bool compareByPhoneNumber(const note* a, const note* b) {
    return a->getPhoneNumber().substr(0, 5) < b->getPhoneNumber().substr(0, 5);
}
void sortByPhoneNumber(vector<note*>& notes) {
    std::sort(notes.begin(), notes.end(), compareByPhoneNumber);
}
void output_vector(vector <note*> notes) {
    sortByPhoneNumber(notes);
    cout << "Отсортированные записи по первым 3 цифрам телефона:\n";
    for (const auto& n : notes) {
        n->noteShow();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<note*> notes;
    char choice;
    string searchLastName;
    while (true) {
        // Выводим опции меню

        std::cout << "===== Меню =====" << std::endl;
        std::cout << "1. Создать запись" << std::endl;
        std::cout << "2. Изменить запись" << std::endl;
        std::cout << "3. Удалить запись" << std::endl;
        std::cout << "4. Вывести на экран записи" << std::endl;
        std::cout << "5. Поиск по фамилии" << std::endl;
        std::cout << "6. Заменить цифры в файле на слова" << std::endl;
        
        std::cout << "0. Выйти из программы" << std::endl;

        // Запрашиваем выбор пользователя

        std::cout << "Введите номер выбранной опции: ";

        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        // Обрабатываем выбор пользователя
        switch (choice) {

        case '1': {
            note newnote;
            string first, last, phone;
            int birth[3];
            cout << "Введите имя: ";
            getline(cin, first);
            newnote.setFirstName(first);
            cout << "Введите фамилию: ";
            getline(cin, last);
            newnote.setLastName(last);
            cout << "Введите номер телефона: ";
            getline(cin, phone);
            newnote.setPhoneNumber(phone);
            cout << "Введите день рождения: ";
            cin >> birth[0];
            cout << "Введите месяц рождения: ";
            cin >> birth[1];
            cout << "Введите год рождения: ";
            cin >> birth[2];
            newnote.setBirthDate(birth);
            notes.push_back(new note(newnote));
            break;
        }
        case '2':
            find_change(notes);
            
            break;
        case '3': {
            find_delete(notes);
            
            break;
        }
        case '4': {
            output_vector(notes);
            break;
        }
        case '5':

            find_lastname(notes);
            
            break;
        case '6': {

            cout << "Введите имя файла: ";
            string loadFileName;
            getline(cin, loadFileName);

            try {
                ifstream ifile(loadFileName);

                if (!ifile) {
                    throw runtime_error("Не удается открыть файл: " + loadFileName);
                }

                cout << "Исходный текст из файла:" << endl;
                cout << "------------------------" << endl;

                string line;
                while (getline(ifile, line)) {
                    cout << line << endl;

                    stringstream ss(line);
                    string word;

                    while (ss >> word) {
                        for (char& c : word) {
                            if (isdigit(c)) {
                                if (c == '0') word = "ноль";
                                else if (c == '1') word = "один";
                                else if (c == '2') word = "два";
                                else if (c == '3') word = "три";
                                else if (c == '4') word = "четыре";
                                else if (c == '5') word = "пять";
                                else if (c == '6') word = "шесть";
                                else if (c == '7') word = "семь";
                                else if (c == '8') word = "восемь";
                                else if (c == '9') word = "девять";
                            }
                            
                        }
                        cout << word << " ";
                        
                        
                    }

                    cout << endl;
                }

                ifile.close();
            }
            catch (const exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
                break;
            }

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
