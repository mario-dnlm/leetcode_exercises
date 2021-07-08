#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int N = matrix.size();
        // int row = (k-1)/N;
        // int col = (k-1)%N;
        // printf("row: %d, col: %d\n",row,col);
        int i =0, j=0;
        int max_row = 0;
        vector<int> cols_idx(N,0);
        k--;
        cols_idx[0]++;
        max_row = i+1;

        while (k>0) {
            int i_this = max_row;
            int search_range = i_this;
            int min_item = matrix[i_this][cols_idx[i_this]];
            for (int row=0; row <= search_range; row++) {
                if (cols_idx[row] < N && min_item > matrix[row][cols_idx[row]]) {
                    min_item = matrix[row][cols_idx[row]];
                    i_this = row;
                }
            }
            i = i_this;
            j = cols_idx[i];
            cols_idx[i]++;
            max_row = (max_row+1 >= N) ? N-1: max_row+1;
            k--;
        }
        return matrix[i][j];
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<vector<int>> matrix= {{1,5,9},{10,11,13},{12,13,15}};
    // int k = 8;
    // vector<vector<int>> matrix= {{-5}};
    // int k = 1;
    vector<vector<int>> matrix= {{1,3,4},{1,8,8},{4,12,17}};
    int k = 5;

    int output = sln.kthSmallest(matrix, k);
    return 0;
}