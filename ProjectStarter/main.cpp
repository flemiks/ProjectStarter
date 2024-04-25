#include <map>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <memory>
#include "Client.cpp"
#include <iostream>

using namespace std;

int main() {
	try {
		auto myClassPtr = make_unique<Client>("phone", "name");
	}
    catch (const ValidationException& ex) {
        std::cout << "ValidationException caught: " << ex.what() << std::endl;
        ex.printViolations();
    }
    catch (const std::exception& ex) {
        std::cout << "Standard exception caught: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception caught" << std::endl;
    }
	
	return 0;
}