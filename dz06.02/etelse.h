#ifndef ETELSE_H
#define ETELSE_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>


class OutOfRangeException : public std::out_of_range {
public:
    OutOfRangeException(const std::string& message) : std::out_of_range(message) {}
};

int calculateValue(const std::string& str);

#endif 