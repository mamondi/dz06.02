#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int sum(int x, int y) {
    if (y == 0) {
        throw exception("Division by zero exception!");
    }
    return x + y;
}

template <typename T>
T inner_input() {
    T value;
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw exception("Input error!");
    }
    return value;
}

template <typename T>
T input(string text) {
    bool is_valid_input = true;
    do {
        cout << text << ": ";
        try {
            is_valid_input = true;
            T x = inner_input<T>();
            return x;
        }
        catch (exception& err) {
            cout << err.what() << endl;
            is_valid_input = false;
        }
    } while (!is_valid_input);
}

