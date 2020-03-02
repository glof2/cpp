#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm> // std::min
#include <cstdint>   // uint64_t

class BigNumber
{
 public:
  using big_digit_t = uint64_t;

 private:
  static constexpr int number_of_digits_per_big_digit = 18;
  static constexpr big_digit_t big_digit_size = 1000000000000000000ULL;    // 10^number_of_digits_per_big_digit

  std::vector<big_digit_t> m_big_digits;

  int number_of_big_digits() const
  {
    return m_big_digits.size();
  }

  big_digit_t operator[](int big_digit_index) const
  {
    return big_digit_index < m_big_digits.size() ? m_big_digits[big_digit_index] : 0;
  }

  big_digit_t& operator[](int big_digit_index)
  {
    while (big_digit_index >= m_big_digits.size())
      m_big_digits.push_back(0);
    return m_big_digits[big_digit_index];
  }

 public:
  // Construct a BigNumber from a string.
  BigNumber(std::string const& s)
  {
    int number_of_digits;
    for (int left = s.size(); left > 0; left -= number_of_digits)
    {
      number_of_digits = std::min(number_of_digits_per_big_digit, left);
      m_big_digits.push_back(std::stoll(s.substr(left - number_of_digits, number_of_digits)));
    }
  }

  BigNumber& operator+=(BigNumber const& rhs)
  {
    int big_digits = std::max(number_of_big_digits(), rhs.number_of_big_digits());
    if (big_digits > number_of_big_digits())
      m_big_digits.resize(big_digits);
    big_digit_t rest = 0;
    for (int big_digit_index = 0; big_digit_index < big_digits; ++big_digit_index)
    {
      m_big_digits[big_digit_index] += rhs[big_digit_index] + rest;
      rest = m_big_digits[big_digit_index] / big_digit_size;
      m_big_digits[big_digit_index] -= rest * big_digit_size;
    }
    if (rest)
      m_big_digits.push_back(rest);
    return *this;
  }

  void print_on(std::ostream& os) const
  {
    auto it = m_big_digits.rbegin();
    os << *it;
    for (++it; it != m_big_digits.rend(); ++it)
      os << std::setfill('0') << std::setw(number_of_digits_per_big_digit) << *it;
  }

  std::string to_string() const
  {
    std::ostringstream oss;
    print_on(oss);
    return oss.str();
  }

  friend std::ostream& operator<<(std::ostream& os, BigNumber const& big_number)
  {
    big_number.print_on(os);
    return os;
  }
};

constexpr int BigNumber::number_of_digits_per_big_digit;
constexpr BigNumber::big_digit_t BigNumber::big_digit_size;

int main()
{
  std::string a = "8982398172539879857129034871239847102986714678174871294387120984704968794875192847918320198409285694376983476982749129834901282309275976";
  std::string b = "9582987312873401948670349687940820394719847619846712381749872958712098570947200129837419857817350918743983475891706817029834791283759862";
  BigNumber an(a);
  BigNumber bn(b);
  an += bn;
  std::cout << an << '\n';
}
