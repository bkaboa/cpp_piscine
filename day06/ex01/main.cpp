#include "main.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	uintptr_t	addr;
	Data		*data = new Data;
	Data		*data2;

	data->str = "je suis charles";

	std::cout << data->str << '\n';
	addr = serialize(data);
	data->str.append("truc");
	data2 = deserialize(addr);
	std::cout << data2->str << '\n';
	delete data;
}
