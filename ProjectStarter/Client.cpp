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
            errors.push_back("Поле телефон повинно дорівнювати 10 цифрам");
        }
        if (!all_of(phone.begin(), phone.end(), ::isdigit)) {
            errors.push_back("Поле телефон повинно включати тільки цифри");
        }
        if (!errors.empty()) {
            violations["phone"] = errors;
        }
        this->phone = phone;
    }

    void setName(string name) {
        vector<string> errors;
        if (name.empty()) {
            errors.push_back("Поле Ім'я не може бути пусте");
        }
        if (!all_of(name.begin(), name.end(), ::isalpha)) {
            errors.push_back("Поле Ім'я не може включати цифри");
        }
        if (name.size() < 2) {
            errors.push_back("Поле Ім'я не може бути менше 2 символів");
        }
        if (name.size() > 24) {
            errors.push_back("Поле Ім'я не може бути більше 24 символів");
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
