//
// Created by user on 01.06.2020.
//

#pragma once
#include <include/IList.hpp>

template<typename T>
class array_list : public IList<T> {
    T* arr_ptr;
    void extend_arr();
public:
    typedef T element_type;
    void append() override;
    void prepend() override;
    void appendall(array_list &arr) override;
    void insertat() override;
    void removeat() override;
    void removeall() override;
    int pop() override;
    int dequeue() override;
    int length() override;
    int getat() override;
};
