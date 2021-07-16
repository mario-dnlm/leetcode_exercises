#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        const int N = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i+2<N; i++) {
            for (int j=i+1; j+1<N; j++) {
                int A_plus_B = nums[i] + nums[j];
                int start = j+1; 
                int end = N-1;
                int mid = start + (end-start)/2;
                while(start < end-1) {
                    if (A_plus_B > nums[mid]) {
                        start = mid;
                    }
                    else {
                        end = mid;
                    }
                    mid = start + (end-start)/2;
                }
                if (A_plus_B > nums[end]) {
                    count += end-j;
                }
                else if (A_plus_B > nums[start]) {
                    count += start - j;
                }
            }
        }

        return count;
    }
};

int main(int argc, char** argv) {
    Solution sln;
    // vector<int>  nums = {2,2,3,4,9,8,10,12};
    // vector<int>  nums = {4,2,3,4};
    vector<int>  nums = {2,2,3,4};
    int output = sln.triangleNumber(nums);
    cout<<"Output: " << output << endl;

    return 0;
}