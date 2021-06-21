#include "stringconvert.h"

#include <sstream>

template <>
bool convertStringTo<bool>(std::string str)
{
    if(str == "true")
        return true;

    return false;
}

template <>
int convertStringTo<int>(std::string str)
{
    return std::stoi(str);
}

template <>
long convertStringTo<long>(std::string str)
{
    return std::stol(str);
}

template <>
float convertStringTo<float>(std::string str)
{
    return std::stof(str);
}

template <>
double convertStringTo<double>(std::string str)
{
    return std::stod(str);
}

template <>
std::vector<int> convertStringTo<std::vector<int>>(std::string str)
{
    std::stringstream ss(str);

    std::vector<int> lstNumber;
    int number = 0;

    while(ss >> number)
        lstNumber.push_back(number);

    return lstNumber;
}

template <>
std::vector<long> convertStringTo<std::vector<long>>(std::string str)
{
    std::stringstream ss(str);

    std::vector<long> lstNumber;
    long number = 0;

    while(ss >> number)
        lstNumber.push_back(number);

    return lstNumber;
}

template <>
std::vector<float> convertStringTo<std::vector<float>>(std::string str)
{
    std::stringstream ss(str);

    std::vector<float> lstNumber;
    float number = 0;

    while(ss >> number)
        lstNumber.push_back(number);

    return lstNumber;
}

template <>
std::vector<double> convertStringTo<std::vector<double>>(std::string str)
{
    std::stringstream ss(str);

    std::vector<double> lstNumber;
    double number = 0;

    while(ss >> number)
        lstNumber.push_back(number);

    return lstNumber;
}