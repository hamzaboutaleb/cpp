#ifndef HARL_CPP
#define HARL_CPP

#include <iostream>
#include <string>

class Harl
{
public:
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error();
};

typedef void (Harl::*HarlFn)(void);

#endif