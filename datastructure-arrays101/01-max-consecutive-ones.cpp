#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            const int n = nums.size();
            
            int count = 0;
            int maxCount = 0;
            
            for (int i=0; i < n; i++) {
                if(nums[i] == 1) {
                    count++;
                } else {
                    // if (maxCount < count) { maxCount = count; }
                    maxCount = max(maxCount, count);
                    count = 0;
                }
            }
            // if (maxCount < count) { maxCount = count; }
        
            return max(maxCount, count);
        }
 };

int main(int argc, char** argv) {
    Solution sln;
    // vector<int> nums = {1,1,0,1,1,1};
    vector<int> nums = {1,0,1,1,0,1};

    int output = sln.findMaxConsecutiveOnes(nums);
    cout << "Output: " << output << endl;
    return 0;
}