/* ************************************************************************
> File Name:     leetcode739.cpp
> Author:        程序员lys
> Created Time:  Fri 22 Apr 2022 01:45:11 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		stack<int> s;
		vector<int> res(n, 0);
				
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
				res[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		
		return res;
    }
};

int main(int argc, char ** argv) {
    Solution sol;
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
    vector<int> result = sol.dailyTemperatures(temperatures);

    for (int r: result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return (0);
}
