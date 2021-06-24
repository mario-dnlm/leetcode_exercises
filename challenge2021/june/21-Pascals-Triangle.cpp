#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j=1; j<i; j++) {
                row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            if (i>0) {
                row.push_back(1);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int numRows = 5;
    vector<vector<int>> output = sln.generate(numRows);

    return 0;
}