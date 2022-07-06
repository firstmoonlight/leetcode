/* ************************************************************************
> File Name:     leetcode139.cpp
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Sun 26 Dec 2021 11:05:40 PM CST
> Description:   
 ************************************************************************/
#include <stdio.h>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false);

        for(int i = 0; i < n; i++){
            for(string word: wordDict){
                int len = word.length();
                if(i - len > 0 && s.substr(i - len, len) == word){
                    dp[i] = dp[i - len];
                }
            }
        }
        
        return dp[n - 1];
    }
};
