class Stack {
public:
    Stack(int capacity) {
        this->capacity = capacity;
        data = new char[capacity];
        top = data;
    }

    ~Stack() {
        delete[] data;
    }

    void push(char symbol) {
        if (top == data + capacity) {
            throw std::runtime_error("Stack overflow");
        }

        *top++ = symbol;
    }

    char pop() {
        if (top == data) {
            throw std::runtime_error("Stack underflow");
        }

        return *--top;
    }

    int size() const {
        return top - data;
    }

    bool empty() const {
        return top == data;
    }

    bool full() const {
        return top == data + capacity;
    }

    void clear() {
        top = data;
    }

    char peek() {
        if (top == data) {
            throw std::runtime_error("Stack underflow");
        }

        return *top;
    }

private:
    int capacity;
    char* data;
    char* top;
};

