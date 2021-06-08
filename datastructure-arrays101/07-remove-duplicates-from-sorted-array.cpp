#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        if (nums.size() < 1) {return 0;}
        while (i < nums.size()) {
            // current value: nums[j]
            
            // find next value
            while (i < nums.size() && nums[i] == nums[j]) { i++; }
            if (i < nums.size()) { nums[++j] = nums[i]; }
            
        }
        return j+1;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = sln.removeDuplicates(nums);

    for(int i=0; i<len; i++) { cout << nums[i] << " ";  } cout << endl;
    return 0;
}