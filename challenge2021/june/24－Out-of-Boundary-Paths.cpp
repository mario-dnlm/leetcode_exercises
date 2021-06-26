#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startColumn >= n || startColumn < 0 || startRow < 0 || startRow >= m) {
            return 1;
        }
        else if (maxMove < 1) {
            return 0;
        }

        const int MODULO =  1e9 + 7;
        vector<vector<int>> grid1(m,vector<int>(n,0));
        vector<vector<int>> grid2(grid1);

        for (int iter=0; iter < maxMove; iter++) {
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    long n1 = (i==0)?1:grid2[i-1][j];
                    long n2 = (i==m-1)?1:grid2[i+1][j];
                    long n3 = (j==0)?1:grid2[i][j-1];
                    long n4 = (j==n-1)?1:grid2[i][j+1];
                    grid1[i][j] = (n1+n2+n3+n4) % MODULO;
                }
            }
            grid2 = grid1;
        }

        return grid1[startRow][startColumn];

        // return findPaths(m,n, maxMove-1, startRow-1, startColumn)%MODULO + findPaths(m,n, maxMove-1, startRow+1, startColumn)%MODULO + findPaths(m,n, maxMove-1, startRow, startColumn-1)%MODULO + findPaths(m,n, maxMove-1, startRow, startColumn+1)%MODULO;
    }
};

int main(int argc, char argv) {
    Solution sln;
    int m = 8;
    int n = 7;
    int maxMove = 16;
    int startRow = 1;
    int startColumn = 5;

    cout << sln.findPaths(m,n,maxMove,startRow,startColumn)<<endl;

    return 0;

}