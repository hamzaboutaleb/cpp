#include <Harl.hpp>

int main()
{
    Harl harl;

    std::cout << "--- Testing INFO ---" << std::endl;
    harl.complain("INFO");
    std::cout << "\n--- Testing DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << "\n--- Testing ERROR ---" << std::endl;
    harl.complain("ERROR");
    std::cout << "\n--- Testing INVALID INPUT ---" << std::endl;
    harl.complain("FATAL");

    return 0;
}