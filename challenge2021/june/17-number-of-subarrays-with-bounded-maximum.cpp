#include <iostream>
#include <vector>
#include <algorithm> // max_element

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        const int N = nums.size();

        int window_size = 1;
        int idx_left = 0;
        int idx_right = 0;
        while (idx_left < N) {
            idx_right = idx_left;
            int max_item = nums[idx_left];
            while(idx_right < N) {
                if(max_item >= left && max_item <= right) {
                    ans++;
                    idx_right++;
                    if (idx_right < N && max_item < nums[idx_right]) {
                        max_item = nums[idx_right];
                    }
                }
                else {
                    idx_right = N;
                }
            }
            idx_left++;
        }

        // while (window_size <= N) {
        //     idx_left = 0;
        //     while(idx_left + window_size - 1 < N) {
        //         int max_item = *max_element(nums.begin()+idx_left, nums.begin()+idx_left + window_size);
        //         if (max_item >= left && max_item <= right) {
        //             ans++;
        //         }
        //         idx_left++;
        //     }
        //     window_size++;            
        // }     
        return ans;
    }

};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {2,1,4,3};
    // int left = 2;
    // int right = 3;
    // vector<int> nums = {2, 9, 2, 5, 6};
    // int left = 2;
    // int right = 8;

    vector<int> nums = {73,55,36,5,55,14,9,7,72,52};
    int left = 32;
    int right = 69;

    int output;

    output = sln.numSubarrayBoundedMax(nums, left, right);
    printf("Output: %d\n", output);

    return 0;
}