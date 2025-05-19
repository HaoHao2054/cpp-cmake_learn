#include "slib.h"
#include "dlib.h"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    // Call the test functions from the libraries
    slib_test();
    dlib_test();
    
    return 0;
}