#include "BitcoinExchange.hpp"

const char *BitCoinExchange::invalid_date::what() const
{
    return "Invalid date";
}

int get_val(std::string string_)
{
    int val;
    std::stringstream ss(string_);
    ss >> val;
    if (ss.fail())
        throw BitCoinExchange::invalid_date();
    ss.clear(); ss.seekg(0);
    return (val);
}

BitCoinExchange::BitCoinExchange()
{
    std::string y;
    std::string m;
    std::string d;
    std::string line;
    std::ifstream db_file("data.ccsv");

    std::string tmp_date;
    std::string tmp_val;
    if (!db_file)
        std::cerr << "Cannot open the db" << std::endl;
    
    while (std::getline(db_file, line))
    {
        std::stringstream ss(line);
        if (line.empty())
            continue;
        std::getline(ss, tmp_date, ',');
        if (tmp_date.empty())
        {
            std::cerr << "No value found" << std::endl;
            return ;
        }
        std::stringstream dated(tmp_date);
        std::getline(dated, y, '-');
        std::getline(dated, m, '-');
        std::getline(dated, d, '-');
        try
        {
            year.push_back(get_val(y));
            month.push_back(get_val(m));
            day.push_back(get_val(d));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        if (dated.str().empty())
            std::cerr << "Error" << std::endl;
    }
    db_file.close();
}
