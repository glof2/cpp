#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
#include <cassert>

std::string input = "3^9*(5+3)/2";
std::string output;

// Read one argument and 'push it on the stack' (write it to 'out'),
// but gobbling up all operators that have higher precedence than current_precedence.
void read_one_argument(std::back_insert_iterator<std::string> out, std::string::const_iterator& in, int precedence_of_current_operator)
{
  // Push the first argument on the stack, either '(' <expression> ')' or <digit>.
  if (*in == '(')
  {
    read_one_argument(out, ++in, 0);    // Decode everything between the '(' and corresponding ')'.
    ++in;                               // Skip over ')'.
  }
  else
    *out++ = *in++;                     // Read a single digit.

  // Translate characters:
  //  0 and ')'   : 0 (termination of for loop).
  //  '+' and '-' : 1
  //  '*' and '/' : 2
  //  '^'         : 3
  static constexpr int precedence_table[] = { 0, 0, 2, 1, 0, 1, 3, 2 };

  int precedence;
  for (;;)
  {
    // Read operator.
    char op = *in;
    int precedence = precedence_table[op & 7];

    // Terminate if the 'op' is '\0' or ')', but also when its precedence is less than or equal that of the current operator.
    if (precedence <= precedence_of_current_operator)
      return;

    // Push second argument on the stack.
    read_one_argument(out, ++in, precedence);
    // Put corresponding operator on the stack.
    *out++ = op;
  }
}

int main()
{
  std::string::const_iterator in = input.begin();

  auto out = std::back_inserter(output);
  read_one_argument(out, in, 0);

  std::cout << output << std::endl;
}
