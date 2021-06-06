#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1) 
            return 0;

        // assigning the elements for nums to myset
        set<int, greater<int>> myset(nums.begin(), nums.end());

        for (set<int,greater<int>>::iterator itr = myset.begin(); itr!=myset.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;

        set<int, greater<int>>::iterator itr = myset.begin();
        int prev = *(itr++);
        int sumCon=1;
        int maxSum=1;
        for (; itr != myset.end(); itr++) {
            if ((*itr) == prev - 1) {
                sumCon++;
                
            } else {
                if (sumCon > maxSum) {
                    maxSum = sumCon;
                }
                sumCon=1;

            }
            prev = *itr;
        }
        if (sumCon > maxSum) {
            maxSum = sumCon;
        }
        return maxSum;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    vector<int> nums = {100,4,200,1,3,2};
    int output;

    output = sln.longestConsecutive(nums);
    cout << "Output: " << output << endl;
    return 0;
}