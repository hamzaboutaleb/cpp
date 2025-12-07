#include <Harl.hpp>

int main(int argc, char *argv[])
{
    Harl harl;

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
        std::cerr << "Example: " << argv[0] << " WARNING" << std::endl;
        return 1;
    }

    std::string filter_level = argv[1];

    harl.complain(filter_level);

    return 0;
}