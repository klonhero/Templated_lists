//
// Created by user on 01.06.2020.
//

#pragma once

template<typename T>
class IList {

public:
    typedef T element_type;
    virtual void append() = 0;
    virtual void prepend() = 0;
    virtual void appendall() = 0;
    virtual void insertat() = 0;
    virtual void removeat() = 0;
    virtual void removeall() = 0;
    virtual int pop() = 0;
    virtual int dequeue() = 0;
    virtual int length() = 0;
    virtual int getat() = 0;
    virtual ~IList() = default;
};