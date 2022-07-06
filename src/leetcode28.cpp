#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> next(m, 0);

        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }
        for (auto n: next) {
            cout << n << " ";
        }
        cout << endl;
        return -1;
    }
};

int main(int argc, char ** argv) {
    Solution s;
    s.strStr("aabaaabaaac", "aabaaac");
    return (0);
}
