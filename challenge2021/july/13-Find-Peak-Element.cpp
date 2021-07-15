#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) {
            return 0;
        } else if (N < 3) {
            return (nums[0] > nums[1]) ? 0 : 1;
        }
        int left = 0;
        int right = N-1;
        while (left < right-1 ) {
            int mid = left + (right - left)/2;
            if (mid == 0 || mid == N-1) { return mid;}
            int slope = nums[mid+1]-nums[mid];
            int slope_lf = nums[mid]-nums[mid-1];
            if (slope_lf>0 && slope<0) {
                return mid;
            }
            // positive slope
            if (slope > 0) {
                left = mid;
            }
            // negative slope
            else if (slope < 0) {
                right = mid;
            } else {
                return mid;
            } 
        }   
        return (nums[left] > nums[right]) ? left : right;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {1,2,1,3,5,6,4};
    // vector<int> nums = {6,5,4,3,2,3,2};
    vector<int> nums = {3,1,2};
    int output = sln.findPeakElement(nums);
    printf("Output: %d\n", output);

    return 0;
}