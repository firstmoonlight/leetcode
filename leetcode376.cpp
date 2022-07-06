#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int max_len = 1;

        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                } else {
                    dp[i][1] = max(dp[i][1], 1);
                    dp[i][0] = max(dp[i][0], 1);
                }
                max_len = max(max_len, max(dp[i][0], dp[i][1]));
            }
        }

        for (auto d : dp) {
            cout << d[0] << ", " << d[1] << endl;
        }

        return max_len;

    }
};

int main() {
    Solution sol;
    vector<int> example = { 1,17,5,10,13,15,10,5,16,8 };
    int res = sol.wiggleMaxLength(example);
    cout << res << endl;
    return (0);
}
