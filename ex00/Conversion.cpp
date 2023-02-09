#include "Conversion.hpp"

Conversion::Conversion() {
    std::cout << "Conversion created" << std::endl;
    setType();
}

Conversion::~Conversion() {
    std::cout << "Conversion destroyed" << std::endl;
}

Conversion::Conversion(const Conversion& other) {
    std::cout << "Conversion created" << std::endl;
    *this = other;
}

Conversion::Conversion(const std::string &str) : _str(str) {
    std::cout << "Conversion created" << std::endl;
}

Conversion &Conversion::operator=(const Conversion& other) {
    return (*this);
}

const char    Conversion::toChar() {
    return 'c';
}

const int     Conversion::toInt() {
    return 0;
}

const float   Conversion::toFloat() {
    return 10.0f;
}

const double  Conversion::toDouble() {
    return 10.0;
}

int          Conversion::isDisplayable(const char  &c) {
    if (c >= 33 && c <= 126)
        return 0;
    else if (c > 127)
        return 1;
    else
        return 2;
}

const   std::string Conversion::printErrorDisplay(const int &result) const {
   
    if (result == 1)
        return ("Non displayable");
    else
        return ("impossible");
}

bool        Conversion::isChar() {
        if (_str.length() == 1) {
            return std::isdigit(_str[0]);
        }
        return false;
}

bool        Conversion::isInt() {

    std::string::size_type pos = 0;

    if (_str[0] != '+' || _str[0] != '-')
        pos++;
    while (pos < _str.length()) {
        if (!std::isdigit(_str[pos]))
            return false;
        pos++;
    }
    return true;
}

bool        Conversion::isFloat() {
    return false;
}

bool        Conversion::isDouble() {
    return false;
}

void        Conversion::setType() {

    this->typeOfstr = -1;

    if (isInt())
        this->typeOfstr = 0;
    if (isFloat())
        this->typeOfstr = 1;
    if (isDouble())
        this->typeOfstr = 2;
    if (isChar())
        this->typeOfstr = 3;

    std::cout << "The type of string is " << typeOfstr << std::endl;
}