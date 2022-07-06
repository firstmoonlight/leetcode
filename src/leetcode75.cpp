#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
            }
        }

        for (int i = l; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
    }

    void sortColors1(vector<int>& nums) {
        int l1 = 0, l2 = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l1]);
                if (l2 > l1) {
                    swap(nums[i], nums[l2]);
                }
                l1++;
                l2++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[l2]);
                l2++;
            }
        }
    }
};

int main(int argc, char ** argv) {
    vector<int> example = { 0,1,2,2,2,1,0,0,2,1,0,1 };
    Solution sol;
    sol.sortColors1(example);

    for (auto i : example) {
        cout << i << " ";
    }
    cout << endl;

    return (0);
}

