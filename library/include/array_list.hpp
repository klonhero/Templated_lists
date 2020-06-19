//
// Created by user on 01.06.2020.
//

#pragma once
#include <cassert>
#include <initializer_list>
#include <stdexcept>
template<typename T>
class array_list {
    T *arr_;
    int size_;
    int capacity_;
    void extend_capacity(int n);
    void reduce_capacity(int n);

public:
    typedef T element_type;
    array_list(array_list &&arrayList) noexcept;
    explicit array_list(int capacity);
    array_list(const array_list &arrayList);
    array_list(const std::initializer_list<T> &list);
    array_list<T> &operator=(const array_list &arrayList);
    void append(const T &value);

    void prepend(const T &value);
    template<typename ICollection>
    void appendall(ICollection &arr) ;
    void insertat(const T &value, int index);
    void removeat(int index);
    void removeall();
    T pop();             //if pop or dequeue return T& -> SIGFLT
    T dequeue();
    int length() const;
    const T& getat(int index) const;
    T &operator[](int index);
    const T &operator[](int index) const;
    T *begin() {
        return &arr_[0];
    }
    T *end() {
        return &arr_[size_];
    }
    virtual ~array_list();
};

template<typename T>
array_list<T>::array_list(const array_list &arrayList) : size_(arrayList.size_), capacity_(arrayList.capacity_) {
    arr_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        arr_[i] = arrayList.arr_[i];
    }
}
template<typename T>
array_list<T>::array_list(array_list &&arrayList) noexcept : arr_(arrayList.arr_), size_(arrayList.size_), capacity_(arrayList.capacity_) {
    arrayList.arr_ = nullptr;
    arrayList.capacity_ = 0;
    arrayList.size_ = 0;
}

template<typename T>
array_list<T>::array_list(int capacity) : size_(0), capacity_(capacity) {
    arr_ = new T[capacity_];
}

template<typename T>
array_list<T>::array_list(const std::initializer_list<T> &list) {
    size_ = list.size();
    capacity_ = size_ * 2;
    arr_ = new T[capacity_];
    int i = 0;
    for (auto &element : list) {
        arr_[i] = element;
        i++;
    }
}
template<typename T>
array_list<T> &array_list<T>::operator=(const array_list &arrayList) {
    if (this == &arrayList) {
        return *this;
    }
    delete[] arr_;
    capacity_ = arrayList.capacity_;
    size_ = arrayList.size_;
    arr_ = new T[capacity_];
    for (int i = 0; i < arrayList.size_; i++) {
        arr_[i] = arrayList.arr_[i];
    }
    return *this;
}
template<typename T>
void array_list<T>::extend_capacity(int n) {
    if (size_ + n > capacity_) {
        int x = 1 + (size_ + n)/ capacity_;
        capacity_ *= x;
        T *new_arr = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            new_arr[i] = arr_[i];
        }
        delete arr_;
        arr_ = new_arr;
    }
}

template<typename T>
void array_list<T>::reduce_capacity(int n) {
    if (size_ - n < capacity_ / 4) {
        while (size_ - n < capacity_ / 4) {
            capacity_ /= 2;
        }
        T *new_arr = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            new_arr[i] = arr_[i];
        }
        delete arr_;
        arr_ = new_arr;
    }
}

template<typename T>
void array_list<T>::append(const T &value) {
    extend_capacity(1);
    arr_[size_] = value;
    size_++;
}

template<typename T>
void array_list<T>::prepend(const T &value) {
    extend_capacity(1);
    for (int i = size_; i > 0; i--) {
        arr_[i] = arr_[i - 1];
    }
    arr_[0] = value;
    size_++;
}

template<typename T>
template<typename ICollection>
void array_list<T>::appendall(ICollection &arr) {
    extend_capacity(arr.length());
    int i = 0;
    for (auto element :arr) {
        arr_[i + size_] = element;
        i++;
    }
    size_ += arr.length();
}

template<typename T>
void array_list<T>::insertat(const T &value, int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    extend_capacity(1);
    for (int i = size_; i > index; i--) {
        arr_[i] = arr_[i - 1];
    }
    arr_[index] = value;
    size_++;
}

template<typename T>
void array_list<T>::removeat(int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    } else if (index < 0){
        throw std::invalid_argument("Invalid argument: index less than zero");
    }
    for (int i = index; i < size_; i++) {
        arr_[i] = arr_[i + 1];
    }
    reduce_capacity(1);
    size_--;
}

template<typename T>
void array_list<T>::removeall() {
    reduce_capacity(size_);
    size_ = 0;
}

template<typename T>
T array_list<T>::pop() {
    T temp = arr_[size_ - 1];
    size_--;
    return temp;
}

template<typename T>
T array_list<T>::dequeue() {
    T temp = arr_[0];
    removeat(0);
    return temp;
}

template<typename T>
int array_list<T>::length() const {
    return size_;
}
template<typename T>
const T& array_list<T>::getat(int index) const { //TODO: Fix
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: index bigger than size");
    }
    return arr_[index];
}
template<typename T>
T &array_list<T>::operator[](int index) {
    return arr_[index];
}
template<typename T>
const T &array_list<T>::operator[](int index) const{
    return arr_[index];
}
template<typename T>
array_list<T>::~array_list() {
    delete[] arr_;
}
