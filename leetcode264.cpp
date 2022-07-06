#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

class Solution {
    std::vector<int> primes = { 2,3,5 };
public:
    int nthUglyNumber(int n) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
		pq.push(1);
		int res = 0;
		
		while (n--) {
			res = pq.top();
            std::cout << res << std::endl;
			pq.pop();
			for (auto prime: primes) {
				if (res < INT_MAX / prime) pq.push(res * prime);
				if (res % prime == 0) break;
			}
		}
		
		return res;
    }
};

int main(int argc, char ** argv)
{
    Solution sol;
    int res = sol.nthUglyNumber(10);
    std::cout << "res is " << res << std::endl;
    return (0);
}
