#include <iostream>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string &stringREF = var;
    std::string *stringPTR = &var;

    std::cout << "Address : " << &var << " - " << &stringREF << " - " << stringPTR << std::endl;
    std::cout << "Values : " << var << " - " << stringREF << " - " << *stringPTR << std::endl;
}