/* ************************************************************************
> File Name:     leetcode218.cpp
> Author:        程序员lys
> Created Time:  Sun 24 Apr 2022 12:19:33 PM CST
> Description:   
 ************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class mycompare {
public:
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
		if (lhs[0] == rhs[0]) {
			return lhs[1] > rhs[1];
		} else {
			return lhs[0] < rhs[0];
		}
	}
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> res;
		vector<vector<int>> points;
		int n = buildings.size();
		
		for (auto building: buildings) {
			points.push_back(vector<int>{building[0], building[2]});
			points.push_back(vector<int>{building[1], -building[2]});
		}
		
		sort(points.begin(), points.end(), mycompare());

        for (auto point: points) {
            cout << "[" << point[0] << ", " <<point[1] << "] ";
        }
        cout << endl;
		
		priority_queue<int> pq;
		unordered_map<int, int> hash;
		int prev = 0;
		
        pq.push(0);
        hash[0] = -1;
		for (int i = 0; i < points.size(); i++) {
			int x = points[i][0];
			int y = points[i][1];
			//if (pq.empty()) {
			//	pq.push(y);
			//	res.push_back(vector<int>{x, y});
			//	hash[y]++;
			//	prev = y;
			//} else {
				//进行判断，判断y的值，如果y的值小于0，那么哈希表中记录其删除信息
				//获取其最大的y轴坐标t，如果t置为删除，那么将t从优先队列中pop出去
				//如果t和prev相等的话，那么跳过，不处理该点
				//如果t和prev不相等的话，那么将其置入res结果中
				if (y < 0) {
                    cout << "y is " << y << " hash y is " << hash[-y] << endl;
					hash[-y]--;
                    cout << "pq.top() is " << pq.top() << endl;
					while (!pq.empty() && hash[pq.top()] == 0) {
                        cout << "pq.top() is " << pq.top() << endl;
						pq.pop();
					}
				} else {
					hash[y]++;
                    cout << "y is " << y << " hash y is " << hash[y] << endl;
					pq.push(y);
				}
				int max_y = pq.top();
                cout << "x is " << x << " max_y is " << max_y << endl;
				if (max_y != prev) {
					res.push_back(vector<int>{x, max_y});
					prev = max_y;
				}
			//}
		}
		
		return res;
    }
};

int main(int argc, char ** argv) {
    Solution sol;
    //vector<vector<int>> src = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
    vector<vector<int>> src = {{ 0,2,3 }, {2,5,3}};
    vector<vector<int>> res = sol.getSkyline(src);

    for (auto r: res) {
        cout << " [";
        for (int v: r){
            cout << v << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return (0);
}
