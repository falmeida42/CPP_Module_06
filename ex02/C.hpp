#ifndef C_H
#define C_H

#include "Base.hpp"

class C : public Base {

    public:
    C() {
        std::cout << "C created" << std::endl;
    }
};

#endif