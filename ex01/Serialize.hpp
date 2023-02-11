#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <stdint.h>
#include <iostream>

typedef struct Data
{
    std::string data;
    int         number;
} Data;

uintptr_t   serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t> (ptr);
}

Data*   deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *> (raw);
}

#endif