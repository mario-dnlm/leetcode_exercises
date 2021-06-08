#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        return j;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {0,1,2,2,3,0,4,2};
    // int val = 2;
    // vector<int> nums = {3,2,2,3};
    // int val = 3;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    
    int len = sln.removeElement(nums, val);
    printf("Output: %d\n", len); cout << endl;
    for(int i=0; i<len;i++) { cout << nums[i] << " ";}cout<<endl;

    return 0;
}