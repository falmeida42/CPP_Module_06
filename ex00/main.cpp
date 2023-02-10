#include "Conversion.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2)
        return (0);
    
    Conversion conv(argv[1]);
    conv.convert();
}