#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

bool isChar(const std::string &literal)
{
  return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool isInt(const std::string &literal)
{
  size_t i = 0;
  if (literal[0] == '-' || literal[0] == '+')
    i++;
  if (i == literal.length())
    return false;
  for (; i < literal.length(); i++)
  {
    if (!std::isdigit(literal[i]))
      return false;
  }
  return true;
}

bool isFloat(const std::string &literal)
{
  if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
    return true;
  size_t i = 0;
  if (literal[0] == '-' || literal[0] == '+')
    i++;
  if (literal[literal.length() - 1] != 'f')
    return false;
  bool hasDecimal = false;
  for (; i < literal.length() - 1; i++)
  {
    if (literal[i] == '.')
    {
      if (hasDecimal)
        return false;
      hasDecimal = true;
    }
    else if (!std::isdigit(literal[i]))
      return false;
  }
  return hasDecimal;
}

bool isDouble(const std::string &literal)
{
  if (literal.length() >= 2 && (literal == "nan" || literal == "+inf" || literal == "-inf"))
    return true;
  size_t i = 0;
  if (literal[0] == '-' || literal[0] == '+')
    i++;
  bool hasDecimal = false;
  for (; i < literal.length(); i++)
  {
    if (literal[i] == '.')
    {
      if (hasDecimal)
        return false;
      hasDecimal = true;
    }
    else if (!std::isdigit(literal[i]))
      return false;
  }
  return hasDecimal;
}

static void printFloat(float v)
{
  if (!std::isinf(v) && !std::isnan(v))
  {
    double intpart;
    if (std::modf(static_cast<double>(v), &intpart) == 0.0 && std::fabs(v) < 1e6f)
      std::cout << "float: " << v << ".0f" << std::endl;
    else
      std::cout << "float: " << v << "f" << std::endl;
  }
  else
    std::cout << "float: " << v << "f" << std::endl;
}

static void printDouble(double v)
{
  if (!std::isinf(v) && !std::isnan(v))
  {
    double intpart;
    if (std::modf(v, &intpart) == 0.0 && std::fabs(v) < 1e6)
      std::cout << "double: " << v << ".0" << std::endl;
    else
      std::cout << "double: " << v << std::endl;
  }
  else
    std::cout << "double: " << v << std::endl;
}

void convertChar(char c)
{
  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  printFloat(static_cast<float>(c));
  printDouble(static_cast<double>(c));
}

void convertInt(const std::string &literal)
{
  char *end;
  long lvalue = std::strtol(literal.c_str(), &end, 10);

  if (lvalue > INT_MAX || lvalue < INT_MIN)
  {
    std::cerr << "Error: Integer overflow." << std::endl;
    return;
  }

  int value = static_cast<int>(lvalue);
  if (value >= 0 && value <= 127 && std::isprint(value))
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << value << std::endl;
  printFloat(static_cast<float>(value));
  printDouble(static_cast<double>(value));
}

void convertFloat(const std::string &literal)
{
  float value = std::strtof(literal.c_str(), NULL);
  double dvalue = std::strtod(literal.c_str(), NULL);
  if (std::isnan(value) || std::isinf(value))
    std::cout << "char: impossible" << std::endl;
  else if (value >= 0 && value <= 127 && std::isprint(static_cast<int>(value)))
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  if (std::isnan(value) || std::isinf(value))
    std::cout << "int: impossible" << std::endl;
  else if (dvalue > static_cast<double>(INT_MAX) || dvalue < static_cast<double>(INT_MIN))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
  printFloat(value);
  printDouble(static_cast<double>(value));
}

void convertDouble(const std::string &literal)
{
  double value = std::strtod(literal.c_str(), NULL);
  if (std::isnan(value) || std::isinf(value))
    std::cout << "char: impossible" << std::endl;
  else if (value >= 0 && value <= 127 && std::isprint(static_cast<int>(value)))
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  if (std::isnan(value) || std::isinf(value))
    std::cout << "int: impossible" << std::endl;
  else if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  printFloat(static_cast<float>(value));
  printDouble(value);
}

void ScalarConverter::convert(const std::string &literal)
{
  if (literal.empty())
  {
    std::cerr << "Error: Empty literal." << std::endl;
    return;
  }

  if (isChar(literal))
    convertChar(literal[0]);
  else if (isInt(literal))
    convertInt(literal);
  else if (isFloat(literal))
    convertFloat(literal);
  else if (isDouble(literal))
    convertDouble(literal);
  else
    std::cerr << "Error: Invalid literal format." << std::endl;
}
