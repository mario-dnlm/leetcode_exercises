#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;

        while (i < nums.size()) {
            if(nums[i] % 2 == 0) {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j++;
            }
            i++;
        }
        return nums;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {3,1,2,4};
    vector<int> output = sln.sortArrayByParity(nums);
    
    return 0;
}