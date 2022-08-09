#pragma once

#include <cstddef>
#include <queue>

using namespace std;

template < typename T, typename Container=deque<T> >
class Stack {
    Container container;
    size_t length;

public:    
    Stack();

    ~Stack();

    Stack& operator=(const Stack& other);

    T& top();

    bool empty() const;

    size_t size() const;

    void push(const T& value);

    void pop();

    void swap(Stack& other);

    template <typename Type, typename Box>
    friend bool operator==(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend bool operator!=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend bool operator<=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend bool operator<(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend bool operator>=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend bool operator>(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs);

    template <typename Type, typename Box>
    friend void print(const Stack<Type, Box>& stack);

};

template <typename T, typename Container>
Stack<T, Container>::Stack(): container(), length(0) {};

template <typename T, typename Container>
Stack<T, Container>::~Stack() {};

template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack<T, Container>& other) {
    container();
    length = other.length;
    for (size_t i; i < other.length; ++i) {
        container.push(other.container[i]);
    }
};

template <typename T, typename Container>
T& Stack<T, Container>::top() {
    return container[length - 1];
};

template <typename T, typename Container>
bool Stack<T, Container>::empty() const {
    if (length == 0) {
        return true;
    }
    return false;
};

template <typename T, typename Container>
size_t Stack<T, Container>::size() const {
    return length;
};

template <typename T, typename Container>
void Stack<T, Container>::push(const T& value) {
    ++length;
    container.push_back(value);
};

template <typename T, typename Container>
void Stack<T, Container>::pop() {
    --length;
    return container.pop_back();
};

template <typename T, typename Container>
void Stack<T, Container>::swap(Stack<T, Container>& other) {


    for (size_t i = 0; i < ((length < other.length) ? length : other.length); ++i) {
        T elemTmp = container[i];
        container[i] = other.container[i];
        other.container[i] = elemTmp;
    }

    if (length < other.length) {
        for (size_t i = other.length - 1; i > length; --i) {
            container.push_back(other.container[i]);
            other.pop();
        }
    } else {
        for (size_t i = length - 1; i > other.length; --i) {
            other.container.push_back(container[i]);
            this->pop();
        }
    }

    length = other.length + length;
    other.length = length - other.length;
    length = length - other.length;

};

template <typename Type, typename Box>
bool operator==(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs.length != rhs.length) {
        return false;
    }
    for (size_t i = 0; i < lhs.length; ++i) {
        if (lhs.container[i] != rhs.container[i]) {
            return false;
        }
    }
    return true;
};

template <typename Type, typename Box>
bool operator!=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs.length == rhs.length) {
        return false;
    }
    size_t count = 0;
    for (size_t i = 0; i < lhs.length; ++i) {
        if (lhs.container[i] == rhs.container[i]) {
            ++count;
        }
    }
    if (count == lhs.length) {
        return false;
    }
    return true;
};

template <typename Type, typename Box>
bool operator<=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs < rhs) {
        return true;
    } else if (lhs == rhs) {
        return true;
    }
    return false;
};

template <typename Type, typename Box>
bool operator<(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs.length > rhs.length) {
        return false;
    } else if (lhs.length < rhs.length) {
        return true;
    }
    for (size_t i = 0; i < lhs.length; ++i) {
        if (lhs.container[i] > rhs.container[i]) {
            return false;
        }
    }
    return true;
};

template <typename Type, typename Box>
bool operator>=(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs > rhs) {
        return true;
    } else if (lhs == rhs) {
        return true;
    }
    return false;
};

template <typename Type, typename Box>
bool operator>(const Stack<Type, Box>& lhs, const Stack<Type, Box>& rhs) {
    if (lhs.length > rhs.length) {
        return true;
    } else if (lhs.length < rhs.length) {
        return false;
    }
    for (size_t i = 0; i < lhs.length; ++i) {
        if (lhs.container[i] < rhs.container[i]) {
            return false;
        }
    }
    return true;
};

template <typename Type, typename Box>
void print(const Stack<Type, Box>& stack) {
    for (size_t i = 0; i < stack.length; ++i) {
        cout << stack.container[i] << ' ';
    }
    cout << endl;
};
