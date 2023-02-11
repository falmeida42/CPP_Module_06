#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void) {

    int random = rand() % 4;

    switch (random)
    {
    case 1:
        return (new A());
        break;
    case 2:
        return (new B());
        break;
    case 3:
        return (new C());
        break;
    default:
        break;
    }
    return NULL;
}

void    identify(Base *p) {

    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "Base class type A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "Base class type B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "Base class type C" << std::endl;
    else
        std::cout << "Not from Base class" << std::endl;
}

void    identify(Base& p) {

    try {
        A a;
        a = dynamic_cast<A&>(p);
        std::cout << "Base class type A" << std::endl;
    } catch (const std::exception& e)
    {
    }
    try {
        B b;
        b = dynamic_cast<B&>(p);
        std::cout << "Base class type B" << std::endl;
    } catch (const std::exception& e)
    {
    }
    try {
        C c;
        c = dynamic_cast<C&>(p);
        std::cout << "Base class type C" << std::endl;
    } catch (const std::exception& e)
    {
    }
}

int main () {

    Base *b1 = generate();
    Base *b2 = generate();
    Base *b3 = generate();
  
    identify(b1);
    identify(b2);
    identify(b3);
    identify(*b1);
    identify(*b2);
    identify(*b3);
}