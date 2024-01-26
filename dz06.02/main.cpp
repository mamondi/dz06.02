#include "etelse.h"

int main() {
    try {
        int x, y;
        x = input<int>("Enter x");
        y = input<int>("Enter y");
        cout << "Result: " << sum(x, y) << endl;
    }
    catch (exception& err) {
        cout << err.what() << endl;
    }
    catch (...) {
        cout << "Unknown error" << endl;
    }
    return 0;
}