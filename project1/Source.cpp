#include <iostream>

int main()
{
  bool running = true;
  int number{ 0 };

  while (running)
  {
  std::cout << "Enter a number: ";
  std::cin >> number;
  
  // !number because 0 == false, and it looks better than number == 0
  if (!number)
  {
    running = false;
  }
  else
  {
    std::cout << number << '\n';
  }
  }
}