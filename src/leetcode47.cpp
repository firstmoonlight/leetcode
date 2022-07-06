#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> arrange;
        vector<int> visited(nums.size(), 0);

        backTrace(res, arrange, nums, visited);

        return res;

    }

    void backTrace(vector<vector<int>>& res, vector<int>& arrange, const vector<int>& nums, vector<int>& visited) {
        if (arrange.size() == nums.size()) {
            res.push_back(arrange);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
                continue;
            visited[i] = 1;
            arrange.push_back(nums[i]);
            backTrace(res, arrange, nums, visited);
            visited[i] = 0;
            arrange.pop_back();
        }
    }
};

int main(int argc, char ** argv) {
    vector<int> example = { 1,2,1 };
    Solution sol;

    vector<vector<int>> res = sol.permuteUnique(example);

    for (auto r: res) {
        for (auto l : r) {
            cout << l << " ";
        }
        cout << endl;
    }
    return (0);
}
