#include "Conversion.hpp"
#include <float.h>
#include <math.h>

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
    bool          onRange = true;
    std::cout << "char: ";

    switch (typeOfstr)
    {
        case 0:
            if (element.Int > 32 && element.Int < 127)
                value = static_cast<unsigned char> (element.Int);
            else
                onRange = false;
            break;
        case 1:
            if (element.Float >= 33 && element.Float <= 126)
                value = static_cast<unsigned char> (element.Float);
            else
                onRange = false;
            break;
        case 2:
            if (element.Double >= 33 && element.Double <= 126)
                value = static_cast<unsigned char> (element.Double);
            else
                onRange = false;
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

    if (onRange == false && typeOfstr != -1)
        std::cout << " not displayable";
    else
        std::cout << " " << value; 
    std::cout << std::endl;
}

void Conversion::toInt() {

    int value = 0;
    bool maxmin = false;

    std::cout << "int: ";

    switch (typeOfstr)
    {
        case 0:
            value = element.Int;   
            break;
        case 1:
            if (element.Float > INT_MAX || element.Float < INT_MIN)
                maxmin = true;
            value = static_cast<int> (element.Float);
            break;
        case 2:
            if (element.Double > INT_MAX || element.Double < INT_MIN)
                maxmin = true;
            value = static_cast<int> (element.Double);
            break;
        case 3:
            value = static_cast<int> (element.Char);
            break;
        case -1:
            break;
        default:
            break;
    }
    
    if (element.isnan == true || element.firstConvError == true || maxmin == true)
        std::cout << "impossible";
    else if (typeOfstr != -1 && element.firstConvError == false)
        std::cout << " " << value;
    std::cout << std::endl;
}

void Conversion::toFloat() {
    float  value;

    std::cout << "float: ";

    switch (typeOfstr)
    {
        case 0:
            value = static_cast<float> (element.Int);
            break;
        case 1:
            value = element.Float;
            break;
        case 2:
            value = static_cast<float> (element.Double);
            break;
        case 3:
            value = static_cast<float> (element.Char);
            break;
        case -1:
            break;
        default:
            break;
    }

    if (element.isnan == true)
        std::cout << "nanf";
    else if (element.firstConvError == false) {
        if (!isinf(value))
            std::cout << std::fixed << std::setprecision(1) << value << "f";
        else
            std::cout << "impossible";
    }
    else
        std::cout << "impossible";
    
    std::cout << std::endl;
}

void Conversion::toDouble() {
    std::cout << "double: ";
    double value = 0.0;

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

    if (element.isnan == true)
        std::cout << "nan";
    else if (typeOfstr == -1 || element.firstConvError == true || isinf(value))
        std::cout << "impossible";
    else
        std::cout << " " << value;
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
            else if (_str.length() > 1) {
                element.isnan = true;
            }
            else {
                return false;
            }
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
            else if (_str.length() > 1) {
                element.isnan = true;
            }
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

    long int li = 0;
    double  db = 0;

    
    std::stringstream stream(_str);

    switch (typeOfstr)
    {
        case 0:
            stream >> li;
            if (li > LONG_MAX || li < LONG_MIN)
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
            if (db > LONG_MAX || db < LONG_MIN)
                element.firstConvError = true;
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