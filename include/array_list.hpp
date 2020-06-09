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
    explicit array_list(int size = 0);
    array_list(const array_list &arrayList);
    array_list(const std::initializer_list<T> &list);
    void append(const T &value);
    void prepend(const T &value);
    template<typename ICollection>
    void appendall(const ICollection *arr);
    void insertat(const T &value, int index);
    void removeat(int index);
    void removeall();
    T &pop();
    T &dequeue();
    int length() const;
    T &getat(int index) const;
    T &operator[](int index);
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
array_list<T>::array_list(int size) : size_(size), capacity_(size * 2) {
    arr_ = new T[capacity_];
}

template<typename T>
array_list<T>::array_list(const std::initializer_list<T> &list) {
    size_ = list.size();
    capacity_ = size_ * 2;
    arr_ = new int[capacity_];
    int i = 0;
    for (auto &element : list) {
        arr_[i] = element;
        i++;
    }
}

template<typename T>
void array_list<T>::extend_capacity(int n) {
    if (size_ + n > capacity_) {
        while (size_ + n > capacity_) {
            capacity_ *= 2;
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
void array_list<T>::appendall(const ICollection *arr) {
    extend_capacity(arr->size);
    for (int i = 0; i < arr->size; i++) {
        arr_[i + size_] = arr[i];
    }
    size_ += arr->size;
}

template<typename T>
void array_list<T>::insertat(const T &value, int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: denominator can't be zero");
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
        throw std::invalid_argument("Invalid argument: denominator can't be zero");
    }
    for (int i = index; i < size_; i++) {
        arr_[i] = arr_[i + 1];
    }
    reduce_capacity(1);
    size_--;
}

template<typename T>
void array_list<T>::removeall() {
    for (int i = 0; i < size_; i++) {
        arr_[i] = nullptr;
    }
    reduce_capacity(size_);
    size_ = 0;
}

template<typename T>
T &array_list<T>::pop() {
    T temp = arr_[size_];
    size_--;
    return temp;
}

template<typename T>
T &array_list<T>::dequeue() {
    T temp = arr_[0];
    removeat(0);
    return temp;
}

template<typename T>
int array_list<T>::length() const {
    return size_;
}
template<typename T>
T &array_list<T>::getat(int index) const {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: denominator can't be zero");
    }
    return arr_[index];
}
template<typename T>
T &array_list<T>::operator[](int index) {
    if (index > size_) {
        throw std::invalid_argument("Invalid argument: denominator can't be zero");
    }
    return getat(index);
}
template<typename T>
array_list<T>::~array_list() {
    delete[] arr_;
}
