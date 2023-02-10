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
        const   std::string printErrorDisplay(const int &result) const;
    public:

        void          convert();
        Conversion();
        Conversion(const std::string &str);
        Conversion(const Conversion& other);
        Conversion &operator=(const Conversion& other);
        ~Conversion();
};

#endif