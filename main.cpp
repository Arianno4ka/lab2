#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char choice;

    while (true) {
        // ������� ����� ����

        std::cout << "===== ���� =====" << std::endl;
        std::cout << "1. �������� �����������" << std::endl;
        std::cout << "2. ���������� �����������" << std::endl;
        std::cout << "3. ������� �����������" << std::endl;
        std::cout << "4. �������� ��������������" << std::endl;
        std::cout << "5. ���������� ��������������" << std::endl;
        std::cout << "6. ������� ��������������" << std::endl;
        std::cout << "7. �������� �������" << std::endl;
        std::cout << "8. ���������� �������" << std::endl;
        std::cout << "9. ������� �������" << std::endl;
        std::cout << "l ���������" << std::endl;
        std::cout << "s ���������" << std::endl;
        std::cout << "0. ����� �� ���������" << std::endl;

        // ����������� ����� ������������

        std::cout << "������� ����� ��������� �����: ";

        std::cin >> choice;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // ������������ ����� ������������
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
            std::cout << "��������� ���������." << std::endl;
            return 0;
        default:
            std::cout << "�������� �����." << std::endl;
            break;
        }
    }
}
