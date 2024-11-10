#include "easyfind.hpp"

int main()
{
    std::list<int> listed;

    listed.push_back(12);
    listed.push_back(112);
    listed.push_back(3112);
    listed.push_back(61);
    listed.push_back(1982);
    try
    {
        std::cout << easyfind(listed, 61) << " Found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

/*
    Associative containers:
    --map

    --set

    --multimap

    --multiset

*/