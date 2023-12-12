#pragma once
#include <iostream>
using namespace std;
class note
{
private:
    string firstName;
    string lastName;
    string phoneNumber;
    int birthDate[3];

public:
    // ������������
    note();
    note(const string& first, const string& last, const string& phone, const int* birth);
    note(const note& other); // ����������� �����������

    // ����������
    ~note();

    // ������ ������� (getters � setters)
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getPhoneNumber() const;
    const int* getBirthDate() const;

    void setFirstName(const string& first);
    void setLastName(const string& last);
    void setPhoneNumber(const string& phone);
    void setBirthDate(const int* birth);

    // ������������� �������� ������� � ����������
    friend ostream& operator<<(std::ostream& os, const note& note);
    friend istream& operator>>(std::istream& is, note& note);
};


