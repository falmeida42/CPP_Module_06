#include "Conversion.hpp"
#include <iostream>

Conversion::Conversion() {
    std::cout << "Conversion created" << std::endl;
}

Conversion::Conversion(const Conversion& other) {

    *this = other;
}

Conversion &Conversion::operator=(const Conversion& other) {
    
}