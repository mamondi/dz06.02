#include <Windows.h>
#include <iostream>
#include "etelse.h"

//Завдання №2
int main() {
    try {
        Stack stack(10);

        stack.push('a');
        stack.push('b');
        stack.push('c');

        for (int i = stack.size() - 1; i >= 0; i--) {
            char symbol = stack.pop();
            std::cout << symbol << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}