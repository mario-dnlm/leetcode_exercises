#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        
        while (i < nums.size()) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {2,1};
    sln.moveZeroes(nums);
    return 0;
}