#include "include/array_list.hpp"
//#include "include/linked_list.hpp"
#include <iostream>
int main() {
    array_list<int> arr {1,2,3,4};
    for (int i = 0; i<arr.length(); i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
    //TODO Template list hard

}
