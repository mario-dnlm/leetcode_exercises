#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<vector<int>> ans;

        if (N<=4) {
            return ans;
        }

        sort(nums.begin(), nums.end());
        for (int h1=0; h1+3<N; h1++) {
            if (nums[h1]*4 > target) { break; } 
            if (nums[h1]+nums.back()*3 < target) { continue; }
            if (h1>0 && nums[h1]==nums[h1-1]) { continue; }

            for (int h2=h1+1; h2+2<N; h2++) {
                if (nums[h1]+nums[h2]*3 > target) { break; }
                if (nums[h1]+nums[h2]+nums.back()*2 < target) { continue; }
                if (h2>h1+1 && nums[h2]==nums[h2-1]) { continue; }

                int left = h2+1;
                int right = N-1;
                if (nums[h1]+nums[h2]+nums[left]*2 > target) { break; }
                if (nums[h1]+nums[h2]+nums[right]*2 < target) { continue; }
                
                while (left < right) {
                    if (nums[h1]+nums[h2]+nums[left]+nums[right]==target) {
                        vector<int> line = {nums[h1],nums[h2],nums[left],nums[right]};
                        ans.push_back(line);
                        left++;
                        right--;
                        while (left<N&&nums[left]==nums[left-1]) { left++; }
                        while (right>h2&&nums[right]==nums[right+1]) {right--; }
                    }
                    else if (nums[h1]+nums[h2]+nums[left]+nums[right]>target) { right--; }
                    else if (nums[h1]+nums[h2]+nums[left]+nums[right]<target) { left++; }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {1,0,-1,0,-2,2};
    // int target = 0;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> output = sln.fourSum(nums, target);

    return 0;
}