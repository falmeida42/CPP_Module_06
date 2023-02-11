#include "Conversion.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "Invalid arguments" << std::endl;
        return (0);
    }
    
    Conversion conv(argv[1]);
    conv.convert();
}