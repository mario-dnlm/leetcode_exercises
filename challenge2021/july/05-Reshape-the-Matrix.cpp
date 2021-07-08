#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        vector<vector<int>> mat2;


        return mat2;        
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<vector<int>> mat = {{1,2}, {3,4}};
    int r=1;
    int c=4;

    vector<vector<int>> output=sln.matrixReshape(mat,r,c);

    return 0;
}