#include "BitcoinExchange.hpp"

const char *BitCoinExchange::invalid_date::what() const throw()
{
    return "Invalid date";
}

BitCoinExchange::~BitCoinExchange()
{
    // for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); it++)
    //     std::cout << "db :" << it->first << "|" << it->second << std::endl;
}

int BitCoinExchange::get_val(std::string string_)
{
    int val;
    std::stringstream ss(string_);
    ss >> val;
    if (ss.fail())
        throw BitCoinExchange::invalid_date();
    ss.clear(); ss.seekg(0);
    return (val);
}

void BitCoinExchange::parse_db()
{
    std::string line, tmp_date, tmp_val;
    std::ifstream db_file("data.csv");

    if (!db_file)
    {
        std::cerr << "[-] Cannot open the db" << std::endl;
        exit(1);
    }
    std::getline(db_file, line); //skip the first line
    while (std::getline(db_file, line))
    {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::getline(ss, tmp_date, ',');
        std::getline(ss, tmp_val);
        std::stringstream vv(tmp_val);

        double  val = get_double(tmp_val);
        if (val < 0.0 || vv.fail() || !check_date(tmp_date))
        {
            std::cerr << "[-] Invalid date" << std::endl;
            continue;
        }
        ss.clear(); ss.seekg(0);
        db.insert(std::make_pair(tmp_date, val));
    }
    db_file.close();
}

void BitCoinExchange::parse_input()
{
    std::string line, tmp_date, tmp_val, btwn;
    std::ifstream db_file(input_file);

    if (!db_file)
    {
        std::cerr << "[-] Cannot open the input file" << std::endl;
        exit(1);
    }
    
    std::getline(db_file, line);
    while (std::getline(db_file, line))
    {
        std::stringstream ss(line);
        if (line.empty())
            continue;
        std::getline(ss, tmp_date, ' ');
        std::getline(ss, btwn, ' ');
        if (btwn != "|")
        {
            std::cerr << "[-] Invalid input" << std::endl;
            continue;
        }
        std::getline(ss, tmp_val, ' ');
        std::stringstream vv(tmp_val);
        double  val = get_double(tmp_val);
        if (val < 0.0 || vv.fail() || !check_date(tmp_date))
        {
            std::cerr << "[-] Invalid input" << std::endl;
            continue;
        }
        ss.clear(); ss.seekg(0);
        std::map<std::string, double>::iterator it = db.upper_bound(tmp_date);
        if (it != db.begin())
            it--;
        else
        {
            std::cerr << "[-] we do not have data before " << db.begin()->first << std::endl;
            continue;
        }

        std::cout << it->first << " => " << val << " = " << it->second * val << std::endl;
    }
    db_file.close();
}

BitCoinExchange::BitCoinExchange(std::string in_file) : input_file(in_file)
{
    parse_db();
    parse_input();
}

bool    BitCoinExchange::is_valid_digits(const std::string val)
{
    if (val.empty())
        return (-1);
    for (size_t index = 0; index < val.size(); index++)
    {
        if (!std::isdigit(val[index]))
            return (-1);
    }
    return (0);
}

int    BitCoinExchange::get_int(const std::string val)
{
    if (is_valid_digits(val))
        return (-1);
    std::stringstream ss(val);
    int a;
    ss >> a;
    if (ss.fail())  //checking for overflow
        return (-1);
    ss.clear(); ss.seekg(0); //TODO maybe remove this
    return (a);
}

double    BitCoinExchange::get_double(const std::string val)
{
    if (val.empty())
        return (-1.0);
    int is_dot = 0;
    for (size_t index = 0; index < val.size(); index++)
    {
        if (val[index] == '.' && index && std::isdigit(val[index + 1]))
            is_dot++;
        else if (is_dot > 1 || !std::isdigit(val[index]) )
            return (-1.0);
    }

    std::stringstream ss(val);
    double a;
    ss >> a;
    if (ss.fail() || a > INT_MAX)  //checking for overflow
        return (-1.0);
    ss.clear(); ss.seekg(0); //TODO maybe remove this
    return (a);
}

bool    BitCoinExchange::check_date(std::string date)
{
    std::stringstream ss_date(date);
    std::string y, m, d;

    std::getline(ss_date, y, '-');
    std::getline(ss_date, m, '-');
    std::getline(ss_date, d);
    int year = get_int(y);
    int month = get_int(m);
    int day = get_int(d);
    if (month <= 0 || month > 12 || year < 0 || day <= 0)
        return (false);
    int max_days;
    switch (month)
    {
        case 2:
            max_days = 28;
            if ((year % 4 == 0 && year % 100) || (year % 400 == 0))
                max_days = 29;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_days = 30;
            break;
        default:
        max_days = 31;
    }
    return (day <= max_days);
}

