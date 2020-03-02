#include <string>
#include <cmath>
#include <iostream>

int toInt(const std::string str)
{
  // Getting the numbers length, and based on that calculating the power needed to create the number
  int topower{ (int) pow( 10, ( str.length() - 1 ) ) };
  
  int finalresult{ 0 };

  for (int index{0}; index != str.length(); index++)
  {
    // Getting number from 'str' in index position 'index'.
    std::string number{""};
    number += str[index];
 
    finalresult += std::stoi( number ) * topower;
    topower /= 10;
  }
  return finalresult;
}

std::string add(const std::string& number1, const std::string& number2)
{
  long long long_a = toInt(number1);
  long long long_b = toInt(number2);
  long long long_result{ long_a + long_b };

  return std::to_string(long_result);
}

int main()
{
  std::cout << add("300", "400");
}
