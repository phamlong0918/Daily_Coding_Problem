#include "test.h"

std::vector<TestCase> createTestCases()
{
    std::vector<TestCase> testCases;

    TestCase testCase_1
    {
        Input { std::vector<int> {1}, 5},
        Output { false }
    };

    TestCase testCase_2
    {
        Input { std::vector<int> {}, 0},
        Output { false }
    };

    TestCase testCase_3
    {
        Input { std::vector<int> {1}, 1},
        Output { false }
    };

    TestCase testCase_4
    {
        Input { std::vector<int> {7, 5}, 12},
        Output { true }
    };

    TestCase testCase_5
    {
        Input { std::vector<int> {5, 3}, 10},
        Output { false }
    };

    TestCase testCase_6
    {
        Input { std::vector<int> {10, 15, 3, 7}, 17},
        Output { true }
    };

    TestCase testCase_7
    {
        Input { std::vector<int> {1, 2, 3, 4, 12, 35, 55, 65, 4, 5, 2, 33}, 68},
        Output { true }
    };

    TestCase testCase_8
    {
        Input { std::vector<int> {1, 2, 3, 4, 12, 35, 55, 65, 4, 5, 2, 33}, 1},
        Output { false }
    };


    testCases.push_back(testCase_1);
    testCases.push_back(testCase_2);
    testCases.push_back(testCase_3);
    testCases.push_back(testCase_4);
    testCases.push_back(testCase_5);
    testCases.push_back(testCase_6);
    testCases.push_back(testCase_7);
    testCases.push_back(testCase_8);

    return testCases;
}

std::vector<std::string> Input::toStrings() const
{
    std::vector<std::string> lines;

    std::string str = "numbers: ";
    for(const auto& number : numbers)
        str += std::to_string(number) + " ";
    lines.push_back(str);

    str = "target: ";
    str += std::to_string(target);
    lines.push_back(str);

    return lines;
}

std::vector<std::string> Output::toStrings() const
{
    if(isEqual == true)
        return {"true"};

    return {"false"};
}

void TestCase::print(std::string headLine) const
{
    auto InputStrs = input.toStrings();
    for(const auto& str : InputStrs)
    {
        std::cout << headLine << str << std::endl;
    }

    auto OutputStrs = expectOutput.toStrings();
    for(const auto& str : OutputStrs)
    {
        std::cout << headLine << "expect: " << str << std::endl;
    }
}