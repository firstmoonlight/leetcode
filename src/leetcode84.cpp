/* ************************************************************************
> File Name:     leetcode84.cpp
> Author:        程序员lys
> Created Time:  Fri 29 Apr 2022 04:00:46 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largestArea = 0;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return heights[0];
        }

        for (int i = 0; i < n; ++i) {
            int min_h = heights[i];
			for (int j = i; j < n; ++j) {
                min_h = min(min_h, heights[j]);
				//int min_h = heights[i];
				//for (int k = i; k <= j; ++k) {
				//	min_h = min(min_h, heights[k]);
				//}
				largestArea = max(largestArea, min_h * (j - i + 1));
                cout << min_h << " " << i << " " << j << endl;
			}
        }

        return largestArea;
    }
};


int main(int argc, char ** argv) {
    Solution solution;
    vector<int> heights = { 2,1,5,6,2,3 };
    //vector<int> heights = {2, 4};
    int res = solution.largestRectangleArea(heights);

    cout << "res is " << res << endl;
    return (0);
}
