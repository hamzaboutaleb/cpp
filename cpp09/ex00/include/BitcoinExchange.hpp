#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void loadDatabase(const std::string &filename);
  void processInput(const std::string &filename) const;

private:
  std::map<std::string, float> _data;

  static bool isValidDate(const std::string &date);
  static bool isValidValue(const std::string &value, float &result);
  static std::string trim(const std::string &str);
  float getRate(const std::string &date) const;
};

#endif
