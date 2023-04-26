#include <map>
#include <string>

#include "Date.hpp"
class BitcoinExchange {
   private:
    std::map<std::string, float> _exchanges;
    void loadExchangeData(std::string filename);
    float isCorrectValue(float value);
    float getExchangeRate(Date date);
    void output(Date date, float value);

   public:
    BitcoinExchange(std::string filepath);
    ~BitcoinExchange();
};