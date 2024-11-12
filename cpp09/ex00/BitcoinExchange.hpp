#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
// #include <utility>
#include <vector>

class BitCoinExchange
{
    private:
        std::vector<int>    year;
        std::vector<int>    month;
        std::vector<int>    day;
        std::string         input_file;

    public:
        BitCoinExchange();
        class	invalid_date : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
};