#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEAS_LEN 100

#include <string>

class Brain
{
private:
    std::string ideas[IDEAS_LEN];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
};
#endif