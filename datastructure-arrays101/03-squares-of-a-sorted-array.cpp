#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/** Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * 
 * 
 */

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

int main(int argc, char** argv) {
    Solution sln;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> output = sln.sortedSquares(nums);
    for(vector<int>::iterator itr=output.begin(); itr!=output.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}