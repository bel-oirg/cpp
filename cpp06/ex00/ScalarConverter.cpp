#include "ScalarConverter.hpp"

void imp()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int check_type(std::string format)
{
	if (format.empty())
		exit(0);
	else if (format == "nan" || format == "+inf" || format == "-inf")
		return (2);
	else if (format == "nanf" || format == "+inff" || format == "-inff" )
		return (1);
	unsigned int	index = 0;
	const char		*str = format.c_str();
	int				is_pt = 0;

	while(str[index])
	{
		if (!index && (str[index] == '-' || str[index] == '+'))
			index++;
		if (!std::isdigit(str[index]))
		{
			if (str[index] == '.' && index && index != (format.size() - 1) && !is_pt)
				is_pt = 1;
			else if (str[index] == 'f' && index == (format.size() - 1)
					&& is_pt && index > 0 && std::isdigit(str[index-1]))
				return (1);
			else
				imp(), exit(1);
		}
		index++;
	}
	return (is_pt);
}

void	char_conv(std::string format)
{
	char	_char = static_cast<char>(format[0]);
	int		_int = static_cast<int>(_char);
	float	_float = static_cast<float>(_int);
	double	_double = static_cast<double>(_float);

	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void	int_conv(int _int, std::string format)
{
	float	_float = static_cast<float>(_int);
	double	_double = static_cast<double>(_float);

	if (_int == atol(format.c_str()))
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
	else
		imp();
}

void ScalarConverter::convert(std::string format)
{
    int     _int = 0;
    char    _char = '\0';
    float   _float = 0.0f;
    double  _double = 0.0;

    bool    imp_int = false;
    bool    imp_float = false;
    bool    imp_double = false;
    bool    imp_char = false;
    bool    non_char = false;

	//CHAR
	if (format.size() == 1 && std::isalpha(format[0]))
		return (char_conv(format));

	int type = check_type(format);

	if (type == 1)
	{
		if (format[format.size() - 1] == 'f')
			format.resize(format.size() - 1);
	}
	std::stringstream ss(format);

	ss >> _int;
	if (ss.fail())
		imp_int = true;
	ss.clear(); ss.seekg(0);

	if (imp_int || _int < -127 || _int > 127)
		imp_char = true;
	else if (_int < 32 || _int > 126)
		non_char = true;
	else
		_char = static_cast<char>(_int);

	ss >> _float;
	if (ss.fail())
		imp_float = true;
	ss.clear(); ss.seekg(0);

	ss >> _double;
	if (ss.fail())
		imp_double = true;
	ss.clear(); ss.seekg(0);

	if (non_char)
		std::cout << "char: Non displayable" << std::endl;
	else if (imp_char)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(_char) << "'" << std::endl;

	if (imp_int)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(_int) << std::endl;
	
	if (!imp_float && !fmod(_float, 1.0))
		std::cout << std::fixed << std::setprecision(1);

	if (imp_float)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(_float) << "f" << std::endl;

	if (imp_double)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(_double) << std::setprecision(13) << std::endl;
}

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}


/*
	seekg(0) moves the internal "get" (read) pointer
	of the stream back to the start.

	by using c_str() i can convert string to const char * and i guarantee the null termination
*/

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