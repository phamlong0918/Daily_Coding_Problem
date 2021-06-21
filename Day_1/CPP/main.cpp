/* 
 * Author: Pham Duc Long
 * Email: phamlong0918@gmail.com
 *
 * This problem was recently asked by Google.
 *
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>
#include <utility>

#include "stringconvert.h"

const std::string TestFile = "test.txt";

std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> getAllTestCases(const std::string& strFileName);
bool readTagContent(std::string& strInput, std::string strTag, int& startIndex, int& endIndex);

bool checkTwoSum(std::vector<int>& numbers, int target);

int main()
{
    // Get all test cases from file test
    auto testCases = getAllTestCases(TestFile);
    int testCaseCount = 0;

    // Check each test case in file
    bool blAllPass = true;
    std::vector<int> lstFailTestCase;
    for(const auto& testCase : testCases)
    {
        testCaseCount ++;
        std::cout << std::endl;
        std::cout << "Test case " << testCaseCount << std::endl;

        // get input and expect output from file test
        std::vector<int> numbers;
        int target;
        bool expectOutput;

        try
        {
            numbers = convertStringTo<std::vector<int>>(testCase.first[0]);
            target = convertStringTo<int>(testCase.first[1]);
            expectOutput = convertStringTo<bool>(testCase.second[0]);
        }
        catch(...)
        {
            std::cout << "Test case " << testCaseCount << " can not be excuted!" << std::endl;
            continue;
        }

        std::cout << "\tnumbers: " << testCase.first[0] << std::endl;
        std::cout << "\ttarget: " << target << std::endl;
        std::cout << "\tExpect output is: " << std::boolalpha << expectOutput << std::endl;

        // check your function
        auto yourOutput = checkTwoSum(numbers, target);
        if(yourOutput != expectOutput)
        {
            blAllPass = false;
            std::cout << "\tYour output is: " << std::boolalpha << yourOutput << std::endl;
            std::cout << "\tFail this test case" << std::endl;
            lstFailTestCase.push_back(testCaseCount);
        }
        else
        {
            std::cout << "\tPass test case " << testCaseCount << std::endl;
        }
    }

    std::cout << std::endl;
    if(blAllPass == true)
        std::cout << "----------All pass----------" << std::endl;
    else
    {
        std::cout << "----------Fail----------" << std::endl;
        std::cout << "Fail at test case";
        for(const auto i : lstFailTestCase)
            std::cout << " " << i;
        std::cout << std::endl;
    }
        

    return 0;
}

/*
// Solution 1: 
bool checkTwoSum(std::vector<int>& numbers, int target)
{
    if(numbers.size() < 2)
        return false;

    for(int i = 0; i < numbers.size() - 1; ++ i)
    {
        for(int j = i + 1; j < numbers.size(); ++ j)
        {
            if(numbers[i] + numbers[j] == target)
                return true;
        }
    }

    return false;
}
*/

/*
// Solution 2: Sort array, after that use two pointers
// Complexity: Sort + Two pointer = O(nlogn) + O(n) = O(nlogn)
bool checkTwoSum(std::vector<int>& numbers, int target)
{
    if(numbers.size() < 2)
        return false;

    sort(numbers.begin(), numbers.end());
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j)
    {
        int s = numbers[i] + numbers[j];
        if(s == target)
            return true;
        else if(s < target)
            ++ i;
        else // if(s > target)
            -- j;
    }
    return false;
}
*/

// Solution 3: Hashtable
// Complexity: O(n)
bool checkTwoSum(std::vector<int>& numbers, int target)
{
    if(numbers.size() < 2)
        return false;

    std::unordered_map<int, int> map;
    for(int i = 0; i < numbers.size(); ++ i)
    {
        if(map[target - numbers[i]] > 0)
            return true;
        else
            ++ map[numbers[i]];
    }

    return false;
}

bool readTagContent(std::string& strInput, std::string strTag, int& startIndex, int& endIndex)
{
    std::string strStartTag = "<" + strTag + ">";
    std::string strEndTag = "</" + strTag + ">";

    if(strInput.size() < strStartTag.size() + strEndTag.size())
        return false;

    for(int i = 0; i < strInput.size() - strStartTag.size() - strEndTag.size(); ++ i)
    {
        if(strInput.substr(i, strStartTag.size()) == strStartTag)
        {
            startIndex = i + strStartTag.size();

            for(int j = startIndex; j < strInput.size() + 1 - strEndTag.size(); ++ j)
            {
                if(strInput.substr(j, strEndTag.size()) == strEndTag)
                {
                    endIndex = j - 1;

                    return true;
                }
            }
        }
    }

    return false;
}

std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> getAllTestCases(const std::string& strFileName)
{
    std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> allTestCases;

    std::ifstream testFile(strFileName);
    std::string strFileContent;

    std::string newLine;
    while(getline(testFile, newLine))
    {
        strFileContent += newLine;
    }

    while(strFileContent.size() > 0)
    {
        int startIndexTC = -1;
        int endIndexTC = -1;

        if(readTagContent(strFileContent, "testcase", startIndexTC, endIndexTC))
        {
            std::string strTestCaseContent = strFileContent.substr(startIndexTC, endIndexTC - startIndexTC + 1);
            strFileContent = strFileContent.substr(endIndexTC + 12, strFileContent.size() + 11 - endIndexTC);
            std::vector<std::string> lstStrInput, lstStrOutput;
            
            while(strTestCaseContent.size() > 0)
            {
                int blBreak = true;
                int startIndexInput, endIndexInput;
                
                // read input
                if(readTagContent(strTestCaseContent, "input", startIndexInput, endIndexInput))
                {
                    blBreak = false;
                    lstStrInput.push_back(strTestCaseContent.substr(startIndexInput, endIndexInput + 1 - startIndexInput));

                    strTestCaseContent = strTestCaseContent.substr(0, startIndexInput - 7) + strTestCaseContent.substr(endIndexInput + 9, strTestCaseContent.size() + 8 - endIndexInput);
                }
                //std::cout << strTestCaseContent + "size: " << (int)strTestCaseContent.size() << std::endl;

                // read output
                int startIndexOutput, endIndexOutput;
                if(readTagContent(strTestCaseContent, "output", startIndexOutput, endIndexOutput))
                {
                    blBreak = false;
                    lstStrOutput.push_back(strTestCaseContent.substr(startIndexOutput, endIndexOutput + 1 - startIndexOutput));

                    strTestCaseContent = strTestCaseContent.substr(0, startIndexOutput - 8) + strTestCaseContent.substr(endIndexOutput + 10, strTestCaseContent.size() + 9 - endIndexOutput);
                }
                //std::cout << strTestCaseContent + "size: " << (int)strTestCaseContent.size() << std::endl;

                if(blBreak == true)
                    break;
            }

            allTestCases.push_back(std::pair<std::vector<std::string>, std::vector<std::string>>(lstStrInput, lstStrOutput));
        }
    }

    return allTestCases;
}