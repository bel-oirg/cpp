#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <float.h>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
	    ScalarConverter();
        
    public:
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter &operator=(const ScalarConverter &eq);
        ~ScalarConverter();
        static void convert(std::string format);
};