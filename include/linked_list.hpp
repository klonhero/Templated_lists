//
// Created by user on 01.06.2020.
//

#pragma once
#include "include/node.hpp"
#include <cassert>
#include <initializer_list>
#include <stdexcept>
template<typename T>
class linked_list {
    node<T> *head_;
    node<T> *tail_;
    int size_;
    node<T> *create_list(int size);

public:
//    class iterator {
//    public:
//        typedef T value_type;
//        typedef std::forward_iterator_tag iterator_category;
//        typedef int difference_type;
//
//        // конструктор
//        iterator(T* ptr) : ptr_(ptr) { }
//
//        iterator operator++();
//        iterator operator++(int junk);
//        T& operator*();
//        T* operator->();
//        bool operator==(const iterator& rhs);
//        bool operator!=(const iterator& rhs);
//    };
    typedef T element_type;
    linked_list(linked_list &&linkedList) noexcept;
    explicit linked_list(int size = 0);
    linked_list(const linked_list &linkedList);
    linked_list(const std::initializer_list<T> &list);
    linked_list<T> &operator=(const linked_list &linkedList);
    void append(const T &value);
    void prepend(const T &value);
    template<typename ICollection>
    void appendall(const ICollection *arr);
    void insertat(const T &value, int index);
    void removeat(int index);
    void removeall();
    T pop();
    T dequeue();
    int length() const;
    T getat(int index) const;
    T &operator[](int index);
//        T *begin() {
//            return &(head_->get());
//        }
//        T *end() {
//            return &(tail_->get());
//        }
    virtual ~linked_list();
};

template<typename T>
linked_list<T>::linked_list(linked_list &&linkedList) noexcept : head_(linkedList.head_), tail_(linkedList.tail_), size_(linkedList.size_) {
    linkedList.size_ = 0;
    linkedList.head_ = nullptr;
    linkedList.tail_ = nullptr;
}

template<typename T>
linked_list<T>::linked_list(int size) : size_(size) {
    head_ = create_list(size_);
    tail_ = head_;
    for (int i = 0; i < size_ -1  ; i++) {
        tail_ = tail_->getnext();
    }
}

template<typename T>
linked_list<T>::linked_list(const linked_list &linkedList) {
    size_ = linkedList.size_;
    head_ = create_list(size_);
    node<T> *temp = head_;
    for (int i = 0; i < size_; i++) {
        temp->set(linkedList.getat(i));
        tail_ = temp;
        temp = temp->getnext();
    }
}

template<typename T>
node<T> *linked_list<T>::create_list(int size) {
    auto* head = new node<T>;
    node<T> *tail = head;
    for (int i = 0; i < size-1; i++) {
        tail->setnext(new node<T>);
        tail = tail->getnext();
    }
    return head;
}

template<typename T>
linked_list<T>::linked_list(const std::initializer_list<T> &list) {
    size_ = list.size();
    head_ = create_list(size_);
    auto temp = head_;
    for (auto &i : list) {
        temp->set(i);
        tail_ = temp;
        temp = temp->getnext();
    }
}

template<typename T>
linked_list<T> &linked_list<T>::operator=(const linked_list &linkedList) {
    if (this == &linkedList) {
        return *this;
    }
    {//delete this list
        auto temp = head_;
        auto temp_next = temp;
        for (int i = 0; i < size_; i++) {
            temp_next = temp->getnext();
            delete temp;
            temp = temp_next;
        }
    }
    size_ = linkedList.size_;
    head_ = create_list(size_);
    auto temp = head_;
    for (int i = 0; i < size_; i++) {// copy linkedList in this
        temp->set(linkedList[i]);
        tail_ = temp;
        temp = temp->getnext();
    }
    return *this;
}

template<typename T>
linked_list<T>::~linked_list() {
    auto temp = head_;
    auto temp_next = temp;
    for (int i = 0; i < size_; i++) {
        temp_next = temp->getnext();
        delete temp;
        temp = temp_next;
    }
}

template<typename T>
T &linked_list<T>::operator[](int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    auto temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->getnext();
    }
    return temp->take();
}

template<typename T>
T linked_list<T>::getat(int index) const {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    auto temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->getnext();
    }
    return temp->get();
}
template<typename T>
void linked_list<T>::append(const T &value) {
    tail_->setnext(new node<T>());
    tail_ = tail_->getnext();
    tail_->set(value);
    size_++;
}
template<typename T>
void linked_list<T>::prepend(const T &value) {
    auto temp = new node<T>;
    temp->setnext(head_);
    head_ = temp;
    size_++;
}
template<typename T>
void linked_list<T>::insertat(const T &value, int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    auto temp = head_;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->getnext();
    }
    temp->setnext(new node<T>);
    temp = temp->getnext();
    temp->set(value);
    size_++;
}
template<typename T>
void linked_list<T>::removeat(int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    auto temp = head_;
    node<T> *temp_previous;
    for (int i = 0; i < index; i++) {
        temp_previous = temp;
        temp = temp->getnext();
    }
    temp_previous->setnext(temp->getnext());
    delete temp;
    size_--;
}
template<typename T>
void linked_list<T>::removeall() {
    auto temp = head_;
    node<T> *temp_next;
    for (int i = 0; i < size_; i++) {
        temp_next = temp->getnext();
        delete temp;
        temp = temp_next;
    }
    size_ = 0;
}
template<typename T>
template<typename ICollection>
void linked_list<T>::appendall(const ICollection *arr) {
    tail_->setnext(create_list(arr->length()));
    for (int i = 0; i < arr->length(); i++) {
        tail_ = tail_->getnext();
        tail_->set(arr->getat(i));
    }
    size_ += arr->length();
}
template<typename T>
T linked_list<T>::pop() {
    if (size_ == 0) {
        throw std::invalid_argument("you can't use pop nothing to return (size = 0)");
    }
    auto temp = head_;
    for (int i = 0; i< size_ - 1; i++){
        temp = temp->getnext();
    }
    size_ = 0;
}
template<typename T>
T linked_list<T>::dequeue() {
    if (size_ == 0) {
        throw std::invalid_argument("you can't use pop nothing to return (size = 0)");
    }
    auto temp = head_;
    head_ = head_->getnext();
    T temp_2 = temp->get();
    delete temp;
    return temp_2;
}

template<typename T>
int linked_list<T>::length() const {
    return size_;
}
