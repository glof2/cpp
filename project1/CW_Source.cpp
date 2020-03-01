#include <iostream>

int main()
{
  constexpr int termination_value = 0;

  for (;;)
  {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number == termination_value)
      break;

    std::cout << number << std::endl;
  }
}
