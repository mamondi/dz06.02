#ifndef ETELSE_H
#define ETELSE_H

#include <iostream>
#include <exception>

class OutOfRangeException : public std::out_of_range {
public:
    OutOfRangeException(const std::string& message) : std::out_of_range(message) {}
};

class MemoryAllocationException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Memory allocation failed.";
    }
};

class EmptyListException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Attempted operation on an empty list.";
    }
};

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void insertFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode) {
            throw MemoryAllocationException();
        }

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode) {
            throw MemoryAllocationException();
        }

        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    T removeFront() {
        if (!head) {
            throw EmptyListException();
        }

        T value = head->data;
        Node<T>* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        return value;
    }

    T removeBack() {
        if (!tail) {
            throw EmptyListException();
        }

        T value = tail->data;
        Node<T>* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        return value;
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

#endif 