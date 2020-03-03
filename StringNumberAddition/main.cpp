#include <string>
#include <cmath>
#include <iostream>

int toInt(std::string const str)
{
  // Getting the numbers length, and based on that calculating the power needed to create the number.
  int topower = std::pow(10, str.length() - 1);

  int finalresult = 0;

  for (int index = 0; index != str.length(); ++index)
  {
    // Getting number from 'str' in index position 'index'.
    std::string number{""};
    number += str[index];

    finalresult += std::stoi(number) * topower;
    topower /= 10;
  }
  return finalresult;
}

std::string add(std::string const& number1, std::string const& number2)
{
  long long long_a = toInt(number1);
  long long long_b = toInt(number2);
  long long long_result = long_a + long_b;

  return std::to_string(long_result);
}

int main()
{
  std::cout << add("300", "400");
}
