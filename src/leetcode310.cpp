/* ************************************************************************
> File Name:     leetcode310.cpp
> Author:        程序员lys
> Created Time:  Tue 31 May 2022 01:46:00 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n, vector<int>{});
		vector<int> res;
		
		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

        for (auto edge : graph) {
            for (auto e : edge) {
                cout << e << " ";
            }
            cout << endl;
        }
		
		//遍历每个点，计算其高度
		vector<vector<int>> points(n, vector<int>{});
		for (int i = 0; i < n; ++i) {
			//vector<int> visited(n, 0);
			int height = bfs(graph, i, n);
            cout << height << endl;
			points[height - 1].push_back(i);
		}
		
		for (auto p : points) {
			if (p.size() != 0) {
				for (auto i : p) {
					res.push_back(i);
				}	
				break;
			}			
		}
		
		return res;
    }
	
	int bfs(vector<vector<int>>& graph, int start, int n) {
		int maxlen = 0;
		queue<int> que;
        vector<int> visited(n, 0);
		visited[start] = 1;
		que.push(start);
		
		while(!que.empty()) {
            int size = que.size();
			maxlen++;
            while (size > 0) {
                int node = que.front();
                cout << node << "---" ;
                que.pop();
                for (int i = 0; i < graph[node].size(); ++i) {
                    if (!visited[graph[node][i]]) {
                        que.push(graph[node][i]);
                        visited[graph[node][i]] = 1;
                    }
                }
                size--;
            }
		}
		
		return maxlen;
	}	
};

int main(int argc, char ** argv) {
    vector<vector<int>> example = { { 1, 0 }, { 1, 2 }, { 1, 3 } };
    int n = 4;

    Solution sol;
    vector<int> res = sol.findMinHeightTrees(n, example);

    for (auto r : res) {
        cout << r << ", ";
    }
    cout << endl;

    return 0;
}
