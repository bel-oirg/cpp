#include "ScalarConverter.hpp"

int check_char(std::string format)
{
	return (format.size() == 1 && !isdigit(format[0]));
}

long    get_int(std::string s_num)
{
	int sign;
	long num;
	int i;

	sign = 1;
	num = 0;
	i = 0;
	if (s_num[i] == '-' || s_num[i] == '+')
		if (s_num[i++] == '-')
			sign = -1;
	while (s_num[i] >= '0' && s_num[i] <= '9')
	{
		num = num * 10 + (s_num[i] - '0');
		if (num *sign >= INT_MAX || num * sign < INT_MIN)
			return (NAN);
		i++;
	}
	if (i < (int)s_num.length())
		return (NAN);
	return (num);
}

int   get_double(std::string s_num, long double *num)
{
	double  fraction;
	int     sign;
	int     i;
	int     is_dot;

	i = 0;
	fraction = 1.0;
	sign = 1;
	is_dot = 0;
	*num = 0.0;
	if (s_num[i] == '-' || s_num[i] == '+')
		if (s_num[i++] == '-')
			sign = -1;
	while(s_num[i])
	{
		if (s_num[i] == '.')
			is_dot = 1;
		else if (isdigit(s_num[i]))
		{
			if (is_dot)
			{
				fraction *= 0.1;
				*num += fraction * (s_num[i] - '0');
			}
			else
				*num = *num * 10 + (s_num[i] - '0');
			if ((sign > 1 && *num > DBL_MAX) || (sign < 0 && sign * *num < DBL_MIN))
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	*num *= sign;
	return (0);
}

int   get_float(std::string s_num, double *num)
{
	float   fraction;
	int     sign;
	int     i;
	int     is_dot;

	i = 0;
	fraction = 1.0;
	sign = 1;
	is_dot = 0;
	*num = 0.0;
	if (s_num[i] == '-' || s_num[i] == '+')
		if (s_num[i++] == '-')
			sign = -1;
	while(s_num[i])
	{
		if (s_num[i] == '.')
			is_dot = 1;
		else if (isdigit(s_num[i]))
		{
			if (is_dot)
			{
				fraction *= 0.1;
				*num += fraction * (s_num[i] - '0');
			}
			else
				*num = *num * 10 + (s_num[i] - '0');
			if (*num * sign > FLT_MAX || *num * sign < FLT_MIN)
				return (-1);
		}
		else if (s_num[i] == 'f' && i == static_cast<int>(s_num.size()) - 1)
			break;
		else
			return (-1);
		i++;
	}
	*num *= sign;
	return (0);
}


int check_double_float(std::string format)
{
	int index;
	int dot;

	dot = 0;
	index = -1;
	while(++index < static_cast<int>(format.size()))
	{
		if (!isdigit(format[index]))
		{
			if (!dot && index < static_cast<int>(format.size()) && format[index] == '.')
				dot = 1;
			else if (dot && format[index] == '.')
				return (0);
			else
				break;
		}
	}
	if (dot && index == static_cast<int>(format.size()))
	{
		if (isdigit(format[index-1]))
			return (2);
	}
	else if (dot && index == static_cast<int>(format.size()) - 1 && format[index] == 'f')
		return (1);
	return (0);
}

int check_int(std::string format)
{
	int index;

	index = -1;
	while(++index < static_cast<int>(format.size()))
	{
		if (!isdigit(format[index]))
			return (0);
	}
	return (1);
}

void ScalarConverter::convert(std::string format)
{
	long double  numb;
	double  fl;


	get_float(format, &fl);
	get_double(format, &numb);

	if (check_char(format))
		std::cout << "char "<< std::endl;

	if (check_int(format))
		std::cout << "int " << get_int(format) << std::endl;
	
	if (check_double_float(format) == 1)
		std::cout << "float " << fl << std::endl;
	
	if (check_double_float(format) == 2 && !get_double(format, &numb))
		std::cout << "double " << numb << std::endl;
}



// void    impos_print(std::string format)
// {
//     std::cout << "char: impossible" << std::endl;
//     std::cout << "Int: impossible" << std::endl;
//     std::cout << "Float: impossible"  << std::endl;
//     std::cout << "Double: impossible" << std::endl;
// }

// void    int_print(std::string format)
// {
//     int _int = static_cast<int> (format[0]);

//     if (std::atoi(format) != std::stol(format)) //overflow
//         return (impos_print(format));
//     if (_int > 32 && _int < 127)
//         std::cout << "char:" << static_cast<char> (_int) << std::endl;
//     else
//         std::cout << "char: Non displayable" << std::endl;
//     std::cout << "int: " << _int << std::endl;
//     std::cout << ""
// }

/*
TYPE CONVESION ON CPP
1- implicit type conversion
	done auto by the compiler
	Ex. -> char a = 12;
		
		-> int c = a + 91 
	[-] it can cause a loss of information

2- explicit type conversion
	- static_cast   (compile time) 

	we cannot static cast the derived class to base class when
	we have prv inheritance
*/