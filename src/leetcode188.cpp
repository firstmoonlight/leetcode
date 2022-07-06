/* ************************************************************************
> File Name:     leetcode188.cpp
> Author:        程序员lys
> Created Time:  Wed 20 Apr 2022 02:37:34 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2, 0)));

        //边界条件
        dp[0][0][0] = -prices[0];
        for (int i = 1; i < n ; ++i) {
            dp[i][0][0] = max(-prices[i], dp[i - 1][0][0]);
        }
        for (int j = 1; j < k; ++j) {
            dp[0][j][0] = dp[0][0][0];
        }

        for (int i = 1; i < n; ++i) {

            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] + prices[i]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }

        }

        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << dp[i][j][0] << " ";
            }
            cout << endl;
        }

        cout << "======================================================" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << dp[i][j][1] << " ";
            }
            cout << endl;
        }

        return dp[n - 1][k - 1][1];
    }
};

int main(int argc, char ** argv) {
    Solution sl;
    int k = 2;
    vector<int> prices = {2,4,1};
    int profit = 0;

    profit = sl.maxProfit(k, prices);

    cout <<  "profit is " << profit << endl;

    return (0);
}
