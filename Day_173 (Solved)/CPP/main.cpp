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

#include "test.h"

std::pair<long, long> findBusiestPeriod(std::vector<Entry> entries);

int main()
{
    // Get all test cases from file test
    auto testCases = createTestCases();

    // Check each test case in file
    bool blAllPass = true;
    std::vector<int> lstFailTestCase;
    for(int i = 0; i < testCases.size(); ++ i)
    {
        std::cout << std::endl;
        std::cout << "Test case " << i + 1 << std::endl;
        testCases[i].print();

        // check your function
        auto yourOutput = findBusiestPeriod(testCases[i].entries);
        if(yourOutput != testCases[i].expectOutput)
        {
            blAllPass = false;
            std::cout << "\tYour output is: " << yourOutput.first << ", " << yourOutput.second << std::endl;
            std::cout << "\tFail this test case" << std::endl;
            lstFailTestCase.push_back(i + 1);
        }
        else
        {
            std::cout << "\tPass test case " << i + 1 << std::endl;
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

std::pair<long, long> findBusiestPeriod(std::vector<Entry> entries)
{
    // sort entries
    int maxPeople = 0;
    int currentPeople = 0;

    int period = 0;
    for(int i = 0; i < entries.size() - 1; ++ i)
    {
        if(entries[i].type == Type::Enter)
            currentPeople += entries[i].count;
        else
            currentPeople -= entries[i].count;

        if(maxPeople < currentPeople)
        {
            maxPeople = currentPeople;
            period = i;
        }
    }

    return {entries[period].timeStamp, entries[period+1].timeStamp};
}

