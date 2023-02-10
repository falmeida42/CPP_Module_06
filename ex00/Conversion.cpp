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
    converter();
    toChar();
    toInt();
    toFloat();
    toDouble();
}

void Conversion::toChar() {

    unsigned char value;
    std::cout << "char: ";

    switch (typeOfstr)
    {
        case 0:
            value = static_cast<unsigned char> (element.Int);
            break;
        case 1:
            value = static_cast<unsigned char> (element.Float);
            break;
        case 2:
            value = static_cast<unsigned char> (element.Double);
            break;
        case 3:
            value = element.Char; 
            break;
        case -1:
            std::cout << "impossible";
            break;
        default:
            break;
    }

    if ((value < 32 || value > 127) && typeOfstr != -1)
        std::cout << " not displayable";
    else
        std::cout << " " << value; 
    std::cout << std::endl;
}

void Conversion::toInt() {

    int value = 0;

    std::cout << "int: ";

    switch (typeOfstr)
    {
        case 0:
            std::cout << element.Int;   
            break;
        case 1:
            value = static_cast<int> (element.Float);
            break;
        case 2:
            value = static_cast<int> (element.Double);
            break;
        case 3:
            value = static_cast<int> (element.Char);
            break;
        case -1:
            std::cout << "impossible";
            break;
        default:
            break;
    }

    std::cout << " " << value;
    std::cout << std::endl;
}

void Conversion::toFloat() {
    std::cout << "float: ";

    switch (typeOfstr)
    {
        case 0:   
            break;
        case 1:
            std::cout << element.Int;
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
    double value = 0;

    switch (typeOfstr)
    {
        case 0:
            value = static_cast<double> (element.Int);
            break;
        case 1:
            value = static_cast<double> (element.Float);
            break;
        case 2:
            value = element.Double; 
            break;
        case 3:
            value = static_cast<double> (element.Char);
            break;
        case -1:
            break;
        default:
            break;
    }


    std::cout << " " << value << std::endl;
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

void      Conversion::converter() {

    std::stringstream stream(_str);
    long int li = 0;
    double  db = 0;
    

    switch (typeOfstr)
    {
        case 0:
            stream >> li;
            if (li > INT_MAX || li < INT_MIN)
                element.firstConvError = true;
            element.Int = static_cast<int> (li);
            break;
        case 1:
            db = std::strtod(_str.c_str(), NULL);
            element.Float = float(db);
            break;
        case 2:
            db = std::strtod(_str.c_str(), NULL);
            db = std::strtod(_str.c_str(), NULL);
            element.Double = std::strtod(_str.c_str(), NULL);
            break;
        case 3:
            stream >> element.Char;
            break;
        case -1:
            break;
        default:
            break;
    }

}