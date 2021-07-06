#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int lf = 0, rf = nums.size() - 1;
        int i = rf;

        while (lf <= rf ) {
            if (abs(nums[lf])  > abs(nums[rf])) {
                ans[i] = nums[lf] * nums[lf];
                lf++;
            } else {
                ans[i] = nums[rf] * nums[rf];
                rf--;
            }
            i--;
        }
        return ans; 
    }
};