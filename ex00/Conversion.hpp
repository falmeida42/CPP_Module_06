#ifndef CONVERSION_HPP
#define CONVERSION_CPP

#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <exception>
#include <limits.h>
#include <limits>
#include <cmath>

#define DBL_MAX
#define DBL_MIN

typedef struct s_elements {
    int     Int;
    float   Float;
    double  Double;
    char    Char;
    bool    firstConvError = false;
    bool    isnan = false;
} elements;

class Conversion {
    private:
        elements   element;
        int     typeOfstr;
        const std::string _str;

        bool isChar();
        bool isFloat();
        bool isDouble();
        bool isInt();

        void toChar();
        void toFloat();
        void toDouble();
        void toInt();

        int     isDisplayable();
        void    setType();
        void    converter();

    public:

        void          convert();
        Conversion();
        Conversion(const std::string &str);
        Conversion(const Conversion& other);
        Conversion &operator=(const Conversion& other);
        ~Conversion();
};

#endif