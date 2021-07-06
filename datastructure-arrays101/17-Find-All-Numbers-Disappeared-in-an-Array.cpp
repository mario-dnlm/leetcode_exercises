#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int j = 1;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] > j) {
                ans.push_back(j);
                j++;
            }
            else if (nums[i] < j) {
                i++;
            }
            else{
                i++; j++;
            }
        }
        while (j  <= nums.size()) {
            ans.push_back(j++);
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {2,2,2,2,2,2,3,1};

    vector<int> output = sln.findDisappearedNumbers(nums);
    return 0;
}