#include "etelse.h"


int main() {
    using namespace std;

    try {
        DoublyLinkedList<int> myList;

        myList.insertFront(1);
        myList.insertFront(2);
        myList.insertBack(3);

        cout << "Removed front: " << myList.removeFront() << endl;
        cout << "Removed back: " << myList.removeBack() << endl;

        myList.clear();

        cout << "Trying to remove from an empty list: ";
        cout << myList.removeFront() << endl;

    }
    catch (const MemoryAllocationException& e) {
        cerr << "Memory Allocation Error: " << e.what() << endl;
    }
    catch (const EmptyListException& e) {
        cerr << "Empty List Error: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}