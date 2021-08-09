#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include <iostream>
#include <utility>

enum Type
{
    Exit,
    Enter
};

struct Entry
{
    long timeStamp;
    int count;
    Type type;
};

struct TestCase
{
    std::vector<Entry> entries;

    std::pair<long, long> expectOutput;

    void print(std::string headLine = "\t")
    {
        std::cout << headLine << "Entries: " << std::endl;

        for(const auto& entry : entries)
        {
            std::cout << headLine + "\t" << "timestamp: " << entry.timeStamp;
            std::cout << "; count: " << entry.count;
            std::cout << "; type: " << ((entry.type == Type::Enter) ? "Enter" : "Exit") << std::endl;
        }
        std::cout << headLine << "expect output: " << expectOutput.first << ", " << expectOutput.second << std::endl;
    }
};

std::vector<TestCase> createTestCases()
{
    std::vector<TestCase> testCases;

    TestCase testCase_1{
        std::vector<Entry>{
            Entry{1526579928, 3, Type::Enter},
            Entry{1526579929, 2, Type::Exit},
            Entry{1526579938, 6, Type::Enter},
            Entry{1526579943, 1, Type::Enter},
            Entry{1526580345, 5, Type::Exit},
            Entry{1526580351, 3, Type::Exit}
        },
        std::pair<long, long> {1526579943, 1526580345}
    };

    testCases.push_back(testCase_1);

    return testCases;
}

#endif