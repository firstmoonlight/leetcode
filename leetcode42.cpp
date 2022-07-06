/* ************************************************************************
> File Name:     leetcode42.cpp
> Author:        程序员lys
> Created Time:  Fri 22 Apr 2022 02:07:05 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		int volum = 0;
        stack<int> s;

		for (int i = 0; i < n; ++i) {
           while (!s.empty() && height[i] > height[s.top()]) {
               int b_h = height[s.top()];
               s.pop();
               if (s.empty())
                   break;
               int left = s.top();
               int t_width = i - left - 1;
               int t_height = min(height[i], height[left]) - b_h;
               volum += t_width * t_height;
           }
           s.push(i);
		}

        return volum;
    }
};

int main(int argc, char ** argv) {
    Solution sol;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int res = sol.trap(height);

    cout << "res is " << res << endl;
    return (0);
}

