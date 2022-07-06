#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int, int> hash;
		int max_len = 0;
		
		for (int i = 0; i < n; ++i) {
			hash[nums[i]] = 1;
		}
		
		for (int i = 0; i < n; ++i) {
            if (!hash[nums[i] + 1]) {
                int tmp = nums[i];
                int tmp_len = 1;
                while (hash[tmp - 1]) {
                    tmp_len++;
                    tmp = tmp - 1;
                }
                max_len = max(max_len, tmp_len);
            }
		}
		
		return max_len;	
    }
};

int main(int argc, char ** argv) {
    Solution so;
    vector<int> src = { 100,4,200,3,1,2 };

    int res = so.longestConsecutive(src);
    cout << "res is " << res << endl;
    return (0);
}
