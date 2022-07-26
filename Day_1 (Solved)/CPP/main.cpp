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

bool checkTwoSum(std::vector<int>& numbers, int target);

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

        // get input, expect output
        auto& numbers = testCases[i].input.numbers;
        int target = testCases[i].input.target;
        bool expectOutput = testCases[i].expectOutput.isEqual;

        testCases[i].print();

        // check your function
        auto yourOutput = checkTwoSum(numbers, target);
        if(yourOutput != expectOutput)
        {
            blAllPass = false;
            std::cout << "\tYour output is: " << std::boolalpha << yourOutput << std::endl;
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

