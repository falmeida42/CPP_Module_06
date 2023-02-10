#include "Conversion.hpp"

Conversion::Conversion() {

}

Conversion::~Conversion() {
}

Conversion::Conversion(const Conversion& other) {
    *this = other;
}

Conversion::Conversion(const std::string &str) : _str(str) {
}

Conversion &Conversion::operator=(const Conversion& other) {
    return (*this);
}

void        Conversion::convert() {

    setType();
    toChar();
    toInt();
    toFloat();
    toDouble();
}

void Conversion::toChar() {
    std::cout << "char: ";

    switch (typeOfstr)
    {
        case 0:   
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            std::cout << _str; 
            break;
        case -1:
            std::cout << "impossible";
            break;
        default:
            break;
    }

    std::cout << std::endl;
}

void Conversion::toInt() {
    std::cout << "int: ";

    switch (typeOfstr)
    {
        case 0:
            std::cout << _str;   
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:

            break;
        case -1:
            std::cout << "impossible";
            break;
        default:
            break;
    }

    std::cout << std::endl;
}

void Conversion::toFloat() {
    std::cout << "float: ";

    switch (typeOfstr)
    {
        case 0:   
            break;
        case 1:
            std::cout << _str; 
            break;
        case 2:
            break;
        case 3:
            break;
        case -1:
            break;
        default:
            break;
    }

    std::cout << std::endl;
}

void Conversion::toDouble() {
    std::cout << "double: ";

    switch (typeOfstr)
    {
        case 0:   
            break;
        case 1:
            break;
        case 2:
            std::cout << _str; 
            break;
        case 3:
            break;
        case -1:
            break;
        default:
            break;
    }

    std::cout << std::endl;
}

int          Conversion::isDisplayable() {
    if (element.Char >= 33 && element.Char <= 126)
        return 0;
    else if (element.Char > 127)
        return 1;
    else
        return 2;
}

const   std::string Conversion::printErrorDisplay(const int &result) const {
   
    if (result == 0)
        return ("Non displayable");
    else
        return ("impossible");
}

bool        Conversion::isChar() {

        if (_str.size() == 1) {
            return !std::isdigit(_str[0]);
        }
        return false;
}

bool        Conversion::isInt() {

    std::string::size_type pos = 0;
    
    if (_str[0] == '+' || _str[0] == '-')
        pos++;
    while (pos < _str.size()) {
        if (!std::isdigit(_str[pos]))
            return false;
        pos++;
    }
    return true;
}

bool        Conversion::isFloat() {

    std::string::size_type pos = 0;
    bool                   dot = false;

    if (_str[0] == '+' || _str[0] == '-')
        pos++;
    while (pos < _str.size() - 1) {
        if (!std::isdigit(_str[pos]))
        {
            if (_str[pos] == '.' && dot == false)
                dot = true;
            else
                return false;
        }
        pos++;
    }
    if (_str[pos] == 'f' && _str.size() > 1)
        return true;
    return false;
}

bool        Conversion::isDouble() {
    
    std::string::size_type pos = 0;
    bool                   dot = false;
    
    if (_str[0] == '+' || _str[0] == '-')
        pos++;
    while (pos < _str.size()) {
        if (!std::isdigit(_str[pos]))
        {
            if (_str[pos] == '.' && dot == false)
                dot = true;
            else
                return false;
        }
        pos++;
    }
    return true;
}

void        Conversion::setType() {

    this->typeOfstr = -1;

    if (isInt())
        this->typeOfstr = 0;
    else if (isFloat())
        this->typeOfstr = 1;
    else if (isDouble())
        this->typeOfstr = 2;
    else if (isChar())
        this->typeOfstr = 3;
    else
        this->typeOfstr = -1;
}