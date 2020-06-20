//
// Created by user on 18.06.2020.
//
#include <array_list.hpp>
#include <gtest/gtest.h>
#include <linked_list.hpp>

TEST(array_list, init_list_test) {
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
TEST(array_list, length_constructor_append_for_auto_tests) {
    array_list<int> arr(10);
    assert(arr.length() == 0);
    std::cout << "arr.length is working" << std::endl;
    for (int i = 0; i < 5; i++) {
        arr.append(5);
    }
    for (auto element : arr) {
        assert(element == 5);
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

TEST(array_list, copy_constructor_appendall_removeat_insertat_removeall_exept_tests) {
    array_list<int> first_arr(10);
    first_arr.append(42);
    first_arr.append(42);
    first_arr.append(42);
    first_arr.append(42);
    for (auto i : first_arr) {
        assert(i == 42);
    }
    assert(first_arr.length() == 4);
    {
        array_list<int> second_arr = first_arr;
        assert(second_arr.length() == 4);
        second_arr.removeat(0);
        assert(second_arr.length() == 3);
        assert(first_arr.length() == 4);
        std::cout << "arr.removeat is working" << std::endl;
        second_arr.insertat(41, 0);
        assert(second_arr[0] == 41);
        assert(second_arr.length() == 4);
        assert(first_arr.length() == 4);
        second_arr.insertat(40, 0);
        assert(second_arr.length() == 5);
        assert(second_arr[0] == 40);
        assert(second_arr[1] == 41);
        std::cout << "arr.insertat is working" << std::endl;
        assert(first_arr.length() == 4);
        second_arr.removeall();
        assert(second_arr.length() == 0);
        std::cout << "arr.removeall is working" << std::endl;
        try {
            second_arr[2];
            std::cout << "Should be exeption" << std::endl;
        } catch (std::exception &ex) {
            std::cout << "exception was catched " << std::endl;
        }
        second_arr.appendall(first_arr);
        for (auto i : second_arr) {
            assert(i == 42);
        }
        assert(second_arr.length() == 4);
        std::cout << "arr.appendall is working with array_list" << std::endl;
    }

    for (auto i : first_arr) {
        assert(i == 42);
    }
    std::cout << "arr copy constructor is working" << std::endl;
}
TEST(array_list, prepend_dequeue_pop_getat_tests) {
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
    assert(arr[arr.length() - 1] == 5);
    assert(arr.length() == 4);
    std::cout << "arr.pop is working" << std::endl;
}
TEST(array_list, const_square_brackets_operator_test) {
    struct A {
        array_list<int> arr{1, 2, 3, 4};

    public:
        int get(int index) const {
            return arr[index];
        }
    };

    {
        A a;
        assert(a.get(1) == 2);
    }
    std::cout << "--------------------End of array_list tests--------------------" << std::endl;
}


TEST(linked_list, init_list_for_auto_append_prepend_remove_removeall_insertat_tests) {
    std::cout << "--------------------Linked_list tests--------------------" << std::endl;
        linked_list<int> arr{1, 2, 3, 4};
        assert(arr.length() == 4);
        int i = 0;
        int j = 1;
        for (auto element : arr) {
            assert(element == j);
            assert(arr[i] == element);
            i++;
            j++;
        }
        std::cout << "arr = {....} is working" << std::endl;
        std::cout << "iterator is working" << std::endl;
        arr.append(5);
        arr.prepend(0);
        assert(arr.length() == 6);
        i = 0;
        for (auto element : arr) {
            assert(element == i);
            i++;
        }
        std::cout << "arr.append is working" << std::endl;
        std::cout << "arr.prepend is working" << std::endl;
        arr.removeat(0);
        i = 1;
        assert(arr.length() == 5);
        for (auto element : arr) {
            assert(element == i);
            i++;
        }
        std::cout << "arr.remove is working" << std::endl;
        arr.removeall();
        assert(arr.length() == 0);
        arr.append(1);
        arr.append(2);
        assert(arr[0] == 1);
        assert(arr[1] == 2);
        std::cout << "arr.removeall is working" << std::endl;
        arr.insertat(3, 2);
        i = 1;
        for (auto element : arr) {
            assert(element == i);
            i++;
        }
        std::cout << "arr.insertat is working" << std::endl;
    }
TEST(linked_list, unique_ptr_tests) {
    //    {
    //        linked_list<std::unique_ptr<int>> arr;
    //        arr.append(std::make_unique<int>(42)); // Вот тут у вас упадет программа с ошибкой, что у unique_ptr нет конструктора копирования или оператора присванивания
    //        assert(*arr[0].get() == 42);
    //    }
    std::cout << "--------------------End of linked_list tests--------------------" << std::endl;
}


TEST(linked_list, append_all) {
    linked_list<int> linkedList1{1, 2, 3, 4, 5, 6, 7};
    linked_list<int> linkedList2{8, 9, 10};
    linkedList1.appendall(linkedList2);
    int i = 1;
    for (auto element:linkedList1) {
        assert(element == i);
        i++;
    }
}


TEST(linked_and_array_list, append_all_tests) {
    std::cout << "--------------------Both lists tests--------------------" << std::endl;

    {
        array_list<int> arrayList{1, 2, 3, 4};
        linked_list<int> linkedList = {5, 6, 7, 8};
        arrayList.appendall(linkedList);
        int i = 1;
        for (auto &element : arrayList) {
            std::cout << element << std::endl;
            assert(element == i);
            i++;
        }
    }

    {
        linked_list<int> linkedList{1, 2, 3, 4};
        array_list<int> arrayList{5, 6, 7, 8};
        linkedList.appendall(arrayList);
        int i = 0;
        for (auto element : linkedList) {
            i++;
            std::cout << element << std::endl;
            assert(element == i);
        }
    }
    std::cout << "arr.appendall with both lists is working" << std::endl;
    std::cout << "--------------------End of both lists tests--------------------" << std::endl;
}
