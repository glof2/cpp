#include <iostream>
#include <string>

void my_copy(std::string::iterator& out, std::string::const_iterator& in)
{
  // write this function using a while loop.
}

int main()
{
  std::string input = "(5-4-1)+9/5/2-7/1/7";
  std::string output;
  std::string::const_iterator in = input.begin();
  std::string::iterator out = output.begin();
  my_copy(out, in);

  std::cout << output << std::endl;
}
