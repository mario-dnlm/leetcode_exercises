#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count = 1;
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end(), greater<int>());

        int thirdMax = nums2[0];
        for(int i=1; i<nums.size() && count<3; i++) {
            if(nums2[i] != nums2[i-1]) {
                count++;
                thirdMax = nums2[i];
            }
        }
        if (count < 3) {
            thirdMax = nums2[0];
        }


        return thirdMax;        
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> heights = {2,2,3,1};

    int output = sln.thirdMax(heights);

    return 0;
}