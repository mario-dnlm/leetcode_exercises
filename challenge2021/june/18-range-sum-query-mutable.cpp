#include <iostream>
#include <vector>
#include <numeric>  // accumulate

using namespace std;

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) : nums(nums){
        
    }

    void update(int index, int val) {
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        
        return accumulate(nums.begin()+left, nums.begin()+right+1, 0);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(int argc, char **argv) {
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);

    return 0;
}