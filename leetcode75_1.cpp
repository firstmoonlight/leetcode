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
        int l1 = 0, l0 = 0;

		//一次遍历，l1标识1的位置，l2标识2的位置
		for (int i = 0; i < nums.size(); ++i) {
			switch (nums[i]) {
				case 2:
					break;
				case 1:
					swap(nums[l1], nums[i]);
					l1++;
					break;
				case 0:
					swap(nums[l0], nums[i]);
					l0++;
					if (l0 > l1) {
						l1 = l0;
					} else {
                        swap(nums[l1], nums[i]);
                        l1++;
                    }
					break;
				default :
					break;
			}
            cout << l0 << ", " << l1 << endl;
		}

		//return nums;
    }
};

int main(int argc, char ** argv) {
    //vector<int> example = { 0,1,2,2,2,1,0,0,2,1,0,1 };
    vector<int> example = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors1(example);

    for (auto i : example) {
        cout << i << " ";
    }
    cout << endl;

    return (0);
}

