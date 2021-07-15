#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int const N = nums.size();
        if (N <= 1) return 1;

        vector<int> dp(N,1);
        int max_dp = 1;
        for(int i=N-2; i>=0; i--) {
            for(int j=N-1; j>i; j--) {
                int cur_max = dp[i];
                if(nums[i]<nums[j] && cur_max < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    
                }
            }
            if (max_dp < dp[i]) {
                max_dp = dp[i];
            }
        }

        return max_dp;
    }
};

int main(int argc, char **argv) {
    Solution sln;

    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    vector<int> nums = {7,7,7,7,7,7};
    int output = sln.lengthOfLIS(nums);

    return 0;
}