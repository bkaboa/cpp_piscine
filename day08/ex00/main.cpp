#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector;
	
	vector.push_back(31);
	vector.push_back(10);
	vector.push_back(78);
	vector.push_back(89);

	std::cout << "VECTOR TEST" << '\n';
	try {
		easyfind(vector, 17);
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}

	try {
		std::cout << "\x1B[32m" << *easyfind(vector, 78) << "\x1B[0m" << '\n';
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}

	std::cout << "LIST TEST" << '\n';
	std::list<int>	list;
	list.push_back(31);
	list.push_back(10);
	list.push_back(78);
	list.push_back(89);
	try {
		easyfind(list, 17);
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}

	try {
		std::cout << "\x1B[32m" << *easyfind(list , 78) << "\x1B[0m" << '\n';
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}

	std::cout << "CONTAINER TEST" << '\n';
	std::deque<int>	container;
	container.push_back(31);
	container.push_back(10);
	container.push_back(78);
	container.push_back(89);
	try {
		easyfind(container, 17);
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}

	try {
		std::cout << "\x1B[32m" << *easyfind(container, 78) << "\x1B[0m" << '\n';
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
	}
	return (0);
}
