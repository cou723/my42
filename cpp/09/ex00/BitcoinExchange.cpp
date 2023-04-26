#include "BitcoinExchange.hpp"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Date.hpp"

bool isNumber(std::string str)
{
    std::stringstream ss(str);
    float n;
    ss >> n;
    return !ss.fail() && ss.eof();
}

void BitcoinExchange::loadExchangeData(std::string filename)
{
    std::ifstream data_file(filename.c_str());
    std::string line;
    bool is_first_line = true;
    while (std::getline(data_file, line))
    {
        if (is_first_line)
        {
            is_first_line = false;
            continue;
        }
        Date date(line.substr(0, line.find(',')));
        std::string exchange_rate = line.substr(line.find(',') + 1);
        this->_exchanges[date.getDate()] = std::atof(exchange_rate.c_str());
    }
    if (this->_exchanges.size() == 0)
        throw std::runtime_error("No exchange");
}

float BitcoinExchange::isCorrectValue(float value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value >= 2147483648)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getExchangeRate(Date date)
{
    if (date < Date(_exchanges.begin()->first))
        throw std::runtime_error("data is too old");
    std::map<std::string, float>::iterator found = this->_exchanges.find(date.getDate());
    Date i_date = date;
    while (found == this->_exchanges.end())
    {
        i_date = i_date.getYesterday();
        found = this->_exchanges.find(i_date.getDate());
    }
    return found->second;
}

BitcoinExchange::BitcoinExchange(std::string filepath)
{
    try
    {
        loadExchangeData("./data.csv");
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: data.csv is not found" << std::endl;
        return;
    }
    std::ifstream input_file(filepath.c_str());
    if (input_file.fail())
        std::cerr << "Error: could not open file." << std::endl;

    std::string line;
    while (std::getline(input_file, line))
    {
        if (line == "date | value")
            continue;
        std::vector<std::string> tokens;
        tokens.push_back("");
        const char *str = line.c_str();
        while (*str != '\0')
        {
            while (*str == ' ')
                str++;
            if (*str == '|')
            {
                tokens.push_back("");
                str++;
                continue;
            }
            tokens.back() += std::string(str, 1);
            str++;
        }
        if (tokens.size() != 2)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        Date date;
        try
        {
            date = Date(tokens[0]);
        }
        catch (std::runtime_error &e)
        {
            std::cerr << "Error: bad date => " << tokens[0] << std::endl;
            continue;
        }
        if (!isNumber(tokens[1]))
        {
            std::cerr << "Error: bad value => " << tokens[1] << std::endl;
            continue;
        }
        float value = std::atof(tokens[1].c_str());
        if (!isCorrectValue(value))
            continue;
        output(date, value);
    }
}

void BitcoinExchange::output(Date date, float value)
{
    float exchange_rate;
    try
    {
        exchange_rate = getExchangeRate(date);
        double result = exchange_rate * value;
        std::cout << date.getDate() << " => " << value << " = " << result << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Error: " << date << " is too old" << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange()
{
}
