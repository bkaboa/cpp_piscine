#ifndef EASYFIND
# define EASYFIND

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <exception>

class NotFoundException : public std::exception {
 public:
  virtual const char *what() const throw() {
    return "Value not found";
  }
};

template<typename T>
typename T::iterator easyfind(T &container, int value) {
  if (std::find(container.begin(), container.end(), value) != container.end()) {
    return std::find(container.begin(), container.end(), value);
  } else {
    throw NotFoundException();
  }
}
#endif
