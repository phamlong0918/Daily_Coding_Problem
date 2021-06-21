#include <string>
#include <vector>

template <typename T>
T convertStringTo(std::string str) {return static_cast<T>(str);}

template <>
bool convertStringTo<bool>(std::string str);

template <>
int convertStringTo<int>(std::string str);

template <>
long convertStringTo<long>(std::string str);

template <>
float convertStringTo<float>(std::string str);

template <>
double convertStringTo<double>(std::string str);

template <>
std::vector<int> convertStringTo<std::vector<int>>(std::string str);

template <>
std::vector<long> convertStringTo<std::vector<long>>(std::string str);

template <>
std::vector<float> convertStringTo<std::vector<float>>(std::string str);

template <>
std::vector<double> convertStringTo<std::vector<double>>(std::string str);