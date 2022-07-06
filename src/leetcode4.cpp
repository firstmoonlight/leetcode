#include <stdio.h>

class Solution {
public:
    //返回第k个元素，k从0开始
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
       int l1 = 0, l2 = 0; 
       int n = nums1.size(), m = nums2.size();

       while (true) {
           if (l1 == nums1.size()) {
               return nums2[l2 + k];
           }
           if (l2 == nums2.size()) {
               return nums1[l1 + k];
           }
           if (k == 0) {
               return min(nums1[l1], nums2[l2]);
           }

           //
           int newl1 = min(l1 + k/2, n - 1);
           int newl2 = min(l2 + k/2, m - 1);
           if (nums1[newl1] <= nums2[newl2]) {
               //nums1中的newl1前面的部分就可以排除了
               l1 = newl1;

           } else {

           }
       }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

int main (int argc, char ** argv) {
    return (0);
}
