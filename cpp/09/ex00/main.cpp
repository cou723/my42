#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char const* argv[]) {
    (void)argc;
    BitcoinExchange b(argv[1] == NULL ? "" : argv[1]);
    return 0;
}

/**
 * input BNF
 * <file> ::= <line>+
 * <line> ::= <date> " | " <exchange>
 * <date> ::= <year> "-" <month> "-" <day>
 * <year> ::= [ 2000 : 2023 ]
 * <month> ::= [ 1 : 12 ]
 * <day> ::= [ 1 : 31 ]
 * <exchange> ::= [ 0 :
 */