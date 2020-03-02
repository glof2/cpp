#include <iostream>
#include <string>
#include <iterator>

void my_copy(std::back_insert_iterator<std::string> out, std::string::const_iterator& in)
{
  // write this function using a while loop.
}

int main()
{
  std::string input = "(5-4-1)+9/5/2-7/1/7";
  std::string output;
  std::string::const_iterator in = input.begin();

  my_copy(std::back_inserter(output), in);

  std::cout << output << std::endl;
}
