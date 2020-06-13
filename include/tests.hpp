//
// Created by user on 10.06.2020.
//

#pragma once
#include "array_list.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>
static void test_array_list() {
    {
        std::cout << "--------------------Array_list tests--------------------" << std::endl;
        array_list<int> arr{1, 2, 3, 4, 5};
        int j = 0;
        for (auto i : arr) {
            j++;
            assert(i == j);
        }
        std::cout << "array_list<int> arr {1,2,3,4,5,} is working" << std::endl;
        std::cout << "for (auto i: arr){...} is working" << std::endl;
    }
    {
        array_list<int> arr(5);
        assert(arr.length() == 5);
        std::cout << "arr.length is working" << std::endl;
        int j = 5;
        for (int &i : arr) {
            i = j;
        }
        for (int i = 0; i < arr.length(); i++) {
            assert(arr[i] == 5);
        }
        arr.append(4);
        assert(arr.length() == 6);
        assert(arr[5] == 4);
        std::cout << "arr.append is working" << std::endl;
        std::cout << "arr[i] is working" << std::endl;
    }

    {
        array_list<int> first_arr(5);
        for (auto &i : first_arr) {
            i = 42;
        }
        for (auto i : first_arr) {
            assert(i == 42);
        }
        {
            array_list<int> second_arr = first_arr;

            assert(second_arr.length() == 5);
            second_arr.removeat(0);
            assert(second_arr.length() == 4);
            std::cout << "arr.removeat is working" << std::endl;
            second_arr.insertat(42,0);
            assert(second_arr.length() == 5);
            assert(second_arr[0] == 42);
            second_arr.insertat(41,0);
            assert(second_arr.length() == 6);
            assert(second_arr[0] == 41);
            assert(second_arr[1] == 42);
            std::cout << "arr.insertat is working" << std::endl;
            assert(first_arr.length() == 5);
            second_arr.removeall();
            assert(second_arr.length() == 0);
            std::cout << "arr.removeall is working" << std::endl;
            try {
                second_arr[2];
                std::cout << "Should be exeption" << std::endl;
            } catch (std::exception &ex) {
                std::cout << "exception was catched " << std::endl;
            }
            second_arr.appendall(&first_arr);
            for (auto i : second_arr) {
                assert(i == 42);
            }
            std::cout << "arr.appendall is working with array_list" << std::endl;
        }
        for (auto i : first_arr) {
            assert(i == 42);
        }
        std::cout << "arr copy constructor is working" << std::endl;
    }
    {
        array_list<int> arr{2, 3, 4, 5, 6};
        arr.prepend(1);
        assert(arr[0] == 1);
        assert(arr.length() == 6);
        std::cout << "arr.prepend is working" << std::endl;
        int temp = arr.dequeue();
        assert(temp == 1);
        assert(arr.getat(0) == 2);
        std::cout << "arr.getat is working" << std::endl;
        assert(arr.length() == 5);
        std::cout << "arr.dequeue is working" << std::endl;
        temp = arr.pop();
        assert(temp == 6);
        assert(arr[arr.length()-1] == 5);
        assert(arr.length() == 4);
        std::cout << "arr.pop is working" << std::endl;
    }
    std::cout << "--------------------End of array_list tests--------------------" << std::endl;


}
static void test_linked_list() {
    {
        std::cout << "--------------------Linked_list tests--------------------" << std::endl;
        linked_list<int> arr{1, 2, 3, 4, 5};
        int j = 0;
        for (int i = 0; i < arr.length();i++) {
            j++;
            assert(arr[i] == j);
        }
        std::cout << "array_list<int> arr {1,2,3,4,5,} is working" << std::endl;
        std::cout << "for (auto i: arr){...} is working" << std::endl;
    }
    {
        linked_list<int> arr(5);
        assert(arr.length() == 5);
        std::cout << "arr.length is working" << std::endl;
        int j = 5;
        for (int i = 0; i < arr.length();i++) {
            arr[i] = j;
        }
        for (int i = 0; i < arr.length(); i++) {
            assert(arr[i] == 5);
        }
        arr.append(4);
        assert(arr.length() == 6);
        assert(arr[5] == 4);
        std::cout << "arr.append is working" << std::endl;
        std::cout << "arr[i] is working" << std::endl;
    }

    {
        linked_list<int> first_arr(5);
        for (int i = 0; i < first_arr.length();i++) {
            i = 42;
        }
        for (int i = 0; i < first_arr.length();i++) {
            assert(first_arr[i] == 42);
        }
        {
            linked_list<int> second_arr = first_arr;

            assert(second_arr.length() == 5);
            second_arr.removeat(0);
            assert(second_arr.length() == 4);
            std::cout << "arr.removeat is working" << std::endl;
            assert(first_arr.length() == 5);
            second_arr.removeall();
            assert(second_arr.length() == 0);
            std::cout << "arr.removeall is working" << std::endl;
            try {
                second_arr[2];
                std::cout << "Should be exeption" << std::endl;
            } catch (std::exception &ex) {
                std::cout << "exception was catched " << std::endl;
            }
            second_arr.appendall(&first_arr);
            for (int i = 0; i < second_arr.length();i++) {//
                assert(second_arr[i] == 42);
            }
            std::cout << "arr.appendall is working with array_list" << std::endl;
        }
        for (int i = 0; i < first_arr.length();i++) {
            assert(first_arr[i] == 42);
        }
        std::cout << "arr copy constructor is working" << std::endl;
    }
    {
        linked_list<int> arr{2, 3, 4, 5, 6};
        arr.prepend(1);
        assert(arr[0] == 1);
        assert(arr.length() == 6);
        std::cout << "arr.prepend is working" << std::endl;
        int temp = arr.dequeue();
        assert(temp == 1);
        assert(arr.getat(0) == 2);
        std::cout << "arr.getat is working" << std::endl;
        assert(arr.length() == 5);
        std::cout << "arr.dequeue is working" << std::endl;
        temp = arr.pop();
        assert(temp == 6);
        assert(arr[arr.length()-1] == 5);
        assert(arr.length() == 4);
        std::cout << "arr.pop is working" << std::endl;
    }
    std::cout << "--------------------End of linked_list tests--------------------" << std::endl;
}