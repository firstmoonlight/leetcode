#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction(vector<int>& lhs, vector<int>& rhs) {
    if (rhs[1] > lhs[1]) {
        return true;
    } else if (rhs[1] < lhs[1]) {
        return false;
    } else {
        return rhs[0] > lhs[0];
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), myfunction);

        //for (auto interval: intervals) {
        //    printf("%d, %d\n", interval[0], interval[1]);
        //}
        
        int numOfOverlap = 0;
        int j = 0;
        //if (intervals[j][1] > intervals[i][0])
        for (int i = 1; i < intervals.size(); ++i) {
            printf("%d, %d\n", i, j);
            if (intervals[j][1] > intervals[i][0]) {
                numOfOverlap++;
            } else {
                j = i;
            }
        }

        return numOfOverlap;
    }
};

int main(int argc, char ** argv) {
    vector<vector<int>> tmp = { {0, 2}, {1,3}, {2,4}, {3,5}, {4,6} };
    Solution sol;
    int res = sol.eraseOverlapIntervals(tmp);;

    printf("%d\n", res);
    return (0);
}
