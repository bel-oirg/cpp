#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>

class BitCoinExchange
{
	private:
		std::map <std::string, double>  db;
		std::map <std::string, double>  stored_db; //TODO
		std::string             input_file;

	public:
		int		get_val(std::string string_);
		int		get_int(const std::string val);
		void	parse_db();
		void	parse_input();
		bool	check_date(std::string date);
		bool    is_valid_digits(const std::string val);
		double	get_double(const std::string val, int is_db);

		BitCoinExchange(std::string in_file);
		~BitCoinExchange();
		class	invalid_date : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};