//
// Created by user on 11.06.2020.
//

#pragma once
template<typename T>
class node {
    T value_;
    node *next_;

public:
    node(const node &Node);
    explicit node(T value, node *next = nullptr);
    node() = default;
    node<T> &operator=(const node &Node);
    T& get();           //return value_
    void set(T value);       //set value in value_
    node<T> *getnext();//return pointer to next node;
    void setnext(node<T> *next);//set next in next_
};


template<typename T>
node<T>::node(const node &Node) {
    value_ = Node.value_;
    next_ = nullptr;
}

template<typename T>
node<T>::node(T value, node *next) : value_(value), next_(next) {
}

template<typename T>
node<T> &node<T>::operator=(const node &Node) {
    if (this == &Node) {
        return *this;
    }
    value_ = Node.value_;
    return *this;
}

template<typename T>
T& node<T>::get() {
    return value_;
}

template<typename T>
void node<T>::set(T value) {
    value_ = value;
}

template<typename T>
node<T> *node<T>::getnext() {
    return next_;
}

template<typename T>
void node<T>::setnext(node *next) {
    next_ = next;
}
