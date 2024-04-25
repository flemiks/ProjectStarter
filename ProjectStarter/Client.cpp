#include "ValidationException.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Client {
public:
    Client(string phone, string name) {
        setPhone(phone);
        setName(name);
        if (!violations.empty()) {
            
            throw ValidationException("Validation errors occurred", violations);
        }
    }
    void setPhone(string phone) {
        vector<string> errors;
        if (phone.size() != 10) {
            errors.push_back("���� ������� ������� ���������� 10 ������");
        }
        if (!all_of(phone.begin(), phone.end(), ::isdigit)) {
            errors.push_back("���� ������� ������� �������� ����� �����");
        }
        if (!errors.empty()) {
            violations["phone"] = errors;
        }
        this->phone = phone;
    }

    void setName(string name) {
        vector<string> errors;
        if (name.empty()) {
            errors.push_back("���� ��'� �� ���� ���� �����");
        }
        if (!all_of(name.begin(), name.end(), ::isalpha)) {
            errors.push_back("���� ��'� �� ���� �������� �����");
        }
        if (name.size() < 2) {
            errors.push_back("���� ��'� �� ���� ���� ����� 2 �������");
        }
        if (name.size() > 24) {
            errors.push_back("���� ��'� �� ���� ���� ����� 24 �������");
        }
        if (!errors.empty()) {
            violations["name"] = errors;
        }
        this->name = name;
    }

    string getName() { return name; }
    string getPhone() { return phone; }
 

private:
    string phone;
    string name;
    map<string, vector<string>> violations;
};
