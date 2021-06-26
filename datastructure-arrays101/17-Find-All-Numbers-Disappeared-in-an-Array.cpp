#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            
        }
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums = {2,2,3,1};

    vector<int> output = sln.findDisappearedNumbers(nums);
    return 0;
}