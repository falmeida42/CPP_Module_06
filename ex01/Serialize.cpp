#include "Serialize.hpp"

int main ()
{
	Data* value = new Data();
	Data* value2;
	value->data = "Ezequiel";
	value->number = 42;
	std::cout << "data before serialize: " << value->data << std::endl;
	std::cout << "number before serialize: " << value->number << std::endl;
	uintptr_t raw = serialize(value);
    std::cout << "  data serialized" << std::endl;
	value2 = deserialize(raw);
    std::cout << "  data deserealized" << std::endl;
	std::cout << "data after serialize: " << value2->data << std::endl;
	std::cout << "number after serialize: " << value2->number << std::endl;
	delete value;
	return 0;
}