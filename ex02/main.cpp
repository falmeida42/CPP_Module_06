#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void) {

    int random = rand() % 4;

    std::cout << random << std::endl;
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

    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Base class type A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Base class type A" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Base class type A" << std::endl;

}

int main () {

    Base *b1 = generate();
    Base *b2 = generate();
    Base *b3 = generate();

    identify(b1);
    identify(b2);
    identify(b3);
}