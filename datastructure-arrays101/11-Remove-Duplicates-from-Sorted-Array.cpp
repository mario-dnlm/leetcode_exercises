#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        
        if(nums.size() < 1) { return 0;}
        while(i + 1 < nums.size()) {
            if(nums[i+1] == nums[i]) {
                i++;
            }
            else {
                nums[j] = nums[i+1];
                j++;
                i++;
            }
        }

        return j;
    }
};
int main(int argc, char **argv) {

    return 0;
}