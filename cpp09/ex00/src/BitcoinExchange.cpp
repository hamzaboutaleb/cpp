#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  if (this != &other)
    _data = other._data;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str)
{
  std::string::size_type start = str.find_first_not_of(" \t\r\n");
  if (start == std::string::npos)
    return "";
  std::string::size_type end = str.find_last_not_of(" \t\r\n");
  return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; i++)
  {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  if (isLeap)
    daysInMonth[1] = 29;

  if (day > daysInMonth[month - 1])
    return false;

  return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, float &result)
{
  if (value.empty())
    return false;

  char *end;
  double val = std::strtod(value.c_str(), &end);
  if (*end != '\0')
    return false;

  result = static_cast<float>(val);
  return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
  std::ifstream file(filename.c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: could not open database file.");

  std::string line;
  if (!std::getline(file, line))
    throw std::runtime_error("Error: empty database file.");

  while (std::getline(file, line))
  {
    std::string::size_type pos = line.find(',');
    if (pos == std::string::npos)
      continue;
    std::string date = trim(line.substr(0, pos));
    std::string valueStr = trim(line.substr(pos + 1));

    float value;
    if (!isValidDate(date) || !isValidValue(valueStr, value))
      continue;
    _data[date] = value;
  }
  file.close();

  if (_data.empty())
    throw std::runtime_error("Error: database is empty or invalid.");
}

float BitcoinExchange::getRate(const std::string &date) const
{
  std::map<std::string, float>::const_iterator it = _data.upper_bound(date);
  if (it == _data.begin())
    throw std::runtime_error("Error: no exchange rate available for this date.");
  --it;
  return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
  std::ifstream file(filename.c_str());
  if (!file.is_open())
  {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  if (std::getline(file, line))
  {
    std::string trimmed = trim(line);
    if (trimmed != "date | value")
    {
      std::string::size_type pos = trimmed.find(" | ");
      if (pos == std::string::npos)
      {
        std::cerr << "Error: bad input => " << trimmed << std::endl;
      }
      else
      {
        std::string date = trim(trimmed.substr(0, pos));
        std::string valueStr = trim(trimmed.substr(pos + 3));
        float value;

        if (!isValidDate(date))
          std::cerr << "Error: bad input => " << date << std::endl;
        else if (!isValidValue(valueStr, value))
          std::cerr << "Error: bad input => " << trimmed << std::endl;
        else if (value < 0)
          std::cerr << "Error: not a positive number." << std::endl;
        else if (value > 1000)
          std::cerr << "Error: too large a number." << std::endl;
        else
        {
          try
          {
            float rate = getRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
          }
          catch (std::exception &e)
          {
            std::cerr << e.what() << std::endl;
          }
        }
      }
    }
  }

  while (std::getline(file, line))
  {
    std::string trimmed = trim(line);
    if (trimmed.empty())
      continue;

    std::string::size_type pos = trimmed.find(" | ");
    if (pos == std::string::npos)
    {
      std::cerr << "Error: bad input => " << trimmed << std::endl;
      continue;
    }

    std::string date = trim(trimmed.substr(0, pos));
    std::string valueStr = trim(trimmed.substr(pos + 3));
    float value;

    if (!isValidDate(date))
      std::cerr << "Error: bad input => " << date << std::endl;
    else if (!isValidValue(valueStr, value))
      std::cerr << "Error: bad input => " << trimmed << std::endl;
    else if (value < 0)
      std::cerr << "Error: not a positive number." << std::endl;
    else if (value > 1000)
      std::cerr << "Error: too large a number." << std::endl;
    else
    {
      try
      {
        float rate = getRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
      }
      catch (std::exception &e)
      {
        std::cerr << e.what() << std::endl;
      }
    }
  }
  file.close();
}
