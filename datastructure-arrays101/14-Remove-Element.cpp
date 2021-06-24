#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int k = sln.removeElement(nums, val);
    
    return 0;
}