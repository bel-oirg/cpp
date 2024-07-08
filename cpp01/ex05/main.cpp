#include "Harl.hpp"

int main(int argc, char *argv[])
{
    //remember the lvel should be 0-3
    if (argc != 2)
    {
        std::cerr << "Invalid number of args" << std::endl;
        return (1);
    }
    std::string lv = argv[1];
    int lv_num = std::stoi(lv);
    if (lv_num <= 0 || lv_num > 4)
    {
        std::cerr << "The lvl of complain should be between 1-4" << std::endl;
        return (1);
    }
    Harl harled;
    harled.complain(lv);
}