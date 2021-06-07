#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int ans = 0;
       
       for (vector<int>::iterator itr=nums.begin(); itr!=nums.end(); itr++) {
           cout << log10(*itr) << " ";
           if ((int)floor(log10(*itr) + 1) % 2 == 0) {
               ans++;
           }
       } 
       return ans;
    }
 };

int main(int argc, char** argv) {
    Solution sln;
    vector<int> nums = {100000, 555,901,482,1771};

    int output = sln.findNumbers(nums);
    cout << "Output: " << output << endl;
    return 0;
}