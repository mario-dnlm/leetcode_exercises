#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>&  nums, int k) {
        if (nums.size() < 1) {return 0;}
        int ans =nums[0];
        
        return ans;
    }

};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {1,-1,-2,4,-7,3};
    int k = 2;
    int output = sln.maxResult(nums, k);

    printf("Output: %d\n", output);

    return 0;
}