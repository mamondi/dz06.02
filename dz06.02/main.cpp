#include "etelse.h"


int calculateValue(const std::string& str) {
    try {
        size_t pos;
        int result = std::stoi(str, &pos);

        if (pos != str.length()) {
            throw std::invalid_argument("Invalid characters in the input string.");
        }

        return result;
    }
    catch (const std::out_of_range& e) {
        throw OutOfRangeException("Value is out of the valid range for int.");
    }
    catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid argument: " + std::string(e.what()));
    }
}

int main() {
    using namespace std;

    cout << "Enter a decimal number: ";
    string input;
    getline(cin, input);

    try {
        int result = calculateValue(input);
        cout << "Result: " << result << endl;
    }
    catch (const OutOfRangeException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}