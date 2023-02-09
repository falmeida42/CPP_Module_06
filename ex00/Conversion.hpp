#ifndef CONVERSION_HPP
#define CONVERSION_CPP
#include <iostream>

typedef struct s_elements {
    int     Int;
    float   Float;
    double  Double;
    char    Char;
} elements;

class Conversion {
    private:
        elements   element;
        int     typeOfstr;
        const std::string _str;
        int    isDisplayable(const char  &c);
        void    setType();
        bool    isChar();
        bool    isInt();
        bool    isFloat();
        bool    isDouble();
        const   std::string printErrorDisplay(const int &result) const;
    public:

        const char    toChar();
        const int     toInt();
        const float   toFloat();
        const double  toDouble();
        Conversion();
        Conversion(const std::string &str);
        Conversion(const Conversion& other);
        Conversion &operator=(const Conversion& other);
        ~Conversion();
};

#endif