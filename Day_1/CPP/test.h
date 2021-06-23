#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include <iostream>

struct Input
{
    std::vector<int> numbers;
    int target;

    std::vector<std::string> toStrings() const;
};

struct Output
{
    bool isEqual;

    std::vector<std::string> toStrings() const;
};

struct TestCase
{
    Input input;
    Output expectOutput;

    void print(std::string headLine = "\t") const;
};

std::vector<TestCase> createTestCases();

#endif