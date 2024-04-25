#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ValidationException : public invalid_argument {
public:
    ValidationException(const char* message, map<string, vector<string>> violations)
        : invalid_argument(message), violations(violations) {}

    void printViolations() const {
        cout << "Validation Errors:" << endl;
        for (const auto& pair : violations) {
            cout << pair.first << " errors:" << endl;
            for (const auto& msg : pair.second) {
                cout << "  - " << msg << endl;
            }
        }
    }

private:
    map<string, vector<string>> violations;
};
