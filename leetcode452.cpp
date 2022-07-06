#include <stdio.h>

bool myfunction (vector<int>& lhs, vector<int>& rhs) {
   if (rhs[1] > lhs[1])  {
       return true;
   } else if (rhs[1] < lhs[1]) {
       return false;
   } else {
       return rhs[0] > lhs[0];
   }
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), myfunction);

        int overlap = 0;
        int j = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[j][1] < points[i][0]) {
                overlap++;
            } else {
                j = i;
            }
        }

        return points.size() - overlap;
    }

};

int main(int argc, char ** argv) {
    return (0);
}
