#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();
        int count = 0;
        
        vector<int> zeros_idx;
        for(int i=0; i<N; i++) {
            if(nums[i]==0) { zeros_idx.push_back(i); }
        }
        // end if there are at most k zeros
        if (zeros_idx.size() <= k) { return N; }
        if (zeros_idx.size() == N) { return k; }
        int i=0, j=0;

        if (k == 0) {
            for (int a=0; a<zeros_idx.size(); ) {
                j = (zeros_idx[a]-1 < N-1) ?zeros_idx[a]-1:N-1;
                count = (count < j-i+1) ? j-i+1 :count;
                i = zeros_idx[a]+1;
                do  {
                    i = zeros_idx[a]+1;
                    a++;
                } while (nums[i]==0 && i<N && a<zeros_idx.size());
                if (a >= zeros_idx.size()) {
                    j = N-1;
                    count = (count < j-i+1) ? j-i+1 :count;
                }
            }
        }
        else {
            // assume there are at least (k+1) zeros
            for (int a=0; a+k<zeros_idx.size(); a++) {
                j = (zeros_idx[a+k]-1 < N-1) ?zeros_idx[a+k]-1:N-1;
                count = (count < j-i+1) ? j-i+1 :count;
                i = zeros_idx[a]+1;
            }
            j = N-1;
            count = (count < j-i+1) ? j-i+1 :count;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    // int k = 2;

    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1};
    // int k = 0;
    // vector<int> nums = {0,0,0,0};
    // int k = 0;
    vector<int> nums = {1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1};
    int k=8;

    int output = sln.longestOnes(nums,k);
    return 0;
}