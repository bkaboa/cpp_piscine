#include "Array.hpp"


void testEmptyArray() {
  Array<int> emptyArray;

  std::cout << "Testing empty array" << std::endl;
  std::cout << "Empty array size: " << emptyArray.getLenght() << std::endl;
}

void testArrayWithSize() {
  Array<int> arrayWithSize(5);
  arrayWithSize[0] = 1;
  arrayWithSize[1] = 2;
  arrayWithSize[2] = 3;
  arrayWithSize[3] = 4;
  arrayWithSize[4] = 5;

  std::cout << "Testing array with size" << std::endl;
  std::cout << "Array with size size: " << arrayWithSize.getLenght() << std::endl;
  arrayWithSize.printArray();
  std::cout << "End of Test\n" << std::endl;
}

void testNegativeIndex() {
  Array<int> arrayWithSize(5);
  arrayWithSize[0] = 1;
  arrayWithSize[1] = 2;
  arrayWithSize[2] = 3;
  arrayWithSize[3] = 4;
  arrayWithSize[4] = 5;

  std::cout << "Testing negative index" << std::endl;
  try {
    arrayWithSize[-1] = 0;
  } catch (std::exception &e) {
    std::cout << "\x1B[31m" << "Exception message: " << e.what() << "\x1B[0m" <<  std::endl;
  }
  std::cout << "End of Test\n" << std::endl;
}

void testIndexSizeOfArray() {
  Array<int> arrayWithSize(2);
  arrayWithSize[0] = 1;
  arrayWithSize[1] = 2;

  std::cout << "Testing index size of array" << std::endl;
  try {
    arrayWithSize[arrayWithSize.getLenght()] = 0;
  } catch (std::exception &e) {
    std::cout << "\x1B[31m" << "Exception message: " << e.what() << "\x1B[0m" <<  std::endl;
  }
  std::cout << "End of Test\n" << std::endl;
}

void testAccesibleReading() {
  Array<int> arrayWithSize(2);
  arrayWithSize[0] = 4;
  arrayWithSize[1] = 2;

  std::cout << "Testing accessible reading" << std::endl;
  std::cout << "Array with size size: " << arrayWithSize.getLenght() << std::endl;
  std::cout << "Array with size[0]: " << arrayWithSize[0] << std::endl;
  std::cout << "Array with size[1]: " << arrayWithSize[1] << std::endl;
  std::cout << "End of Test\n" << std::endl;
}

void testAccesibleWriting() {
  Array<int> arrayWithSize(2);
  arrayWithSize[0] = 4;
  arrayWithSize[1] = 2;

  std::cout << "Testing accessible writing" << std::endl;
  std::cout << "Array before writing" << std::endl;
  arrayWithSize.printArray();
  std::cout << "Array after writing" << std::endl;
  arrayWithSize[0] = 1;
  arrayWithSize[1] = 2;
  arrayWithSize.printArray();
  std::cout << "End of Test\n" << std::endl;
}

void testCopy() {
  Array<int> arrayWithSize(2);
  arrayWithSize[0] = 4;
  arrayWithSize[1] = 2;

  Array<int> copyArray(arrayWithSize);

  std::cout << "Testing copy" << std::endl;
  std::cout << "Array before copy" << std::endl;
  arrayWithSize.printArray();
  std::cout << "Copy array" << std::endl;
  copyArray.printArray();
  copyArray[0] = 1;
  copyArray[1] = 122;
  std::cout << " Modified copy array: " << std::endl;
  copyArray.printArray();
  std::cout << "Original array: " << std::endl;
  arrayWithSize.printArray();
  std::cout << "End of Test\n" << std::endl;
}

void testConstWriting() {
  int *intArray = new int[2];
  intArray[0] = 4;
  intArray[1] = 2;
  const Array<int> arrayWithSize(intArray, 2);
  delete[] intArray;
  std::cout << "Testing const writing" << std::endl;
  std::cout << "arrayWithSize[0]: " << arrayWithSize[0] << std::endl;
  std::cout << "arrayWithSize[1]: " << arrayWithSize[1] << std::endl;
//  arrayWithSize[0] = 1;
  std::cout << "End of Test\n" << std::endl;
}

int main() {
  testEmptyArray();
  testArrayWithSize();
  testNegativeIndex();
  testIndexSizeOfArray();
  testAccesibleReading();
  testAccesibleWriting();
  testCopy();
  testConstWriting();
  return 0;
}
