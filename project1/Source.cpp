#include <iostream>

int main()
{
  bool running = true;
  int number{ 0 };
  const int endnumber{ 0 };

  while (running)
  {
    std::cout << "Enter a number: ";
    std::cin >> number;
  
    if (number == endnumber)
    {
      running = false;
    }
    else
    {
      std::cout << number << '\n';
    }
  }
}