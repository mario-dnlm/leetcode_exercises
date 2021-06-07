#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/** Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place, do not return anything from your function.
 * 
 * 
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int N = arr.size();
        const vector<int> arr2(arr);

        int i = 0, j = 0;
        while(i < N) {
            if(arr2[j] != 0) {
                arr[i++] = arr2[j++];
            } else {
                arr[i]  = 0;
                if (i+1 < N) { arr[i+1] = 0; }
                j++;
                i+=2;
            }
        }

        
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int lf = 0, rf = nums.size() - 1;
        int i = rf;

        while (lf <= rf ) {
            if (abs(nums[lf])  > abs(nums[rf])) {
                ans[i] = nums[lf] * nums[lf];
                lf++;
            } else {
                ans[i] = nums[rf] * nums[rf];
                rf--;
            }
            i--;
        }
        return ans;    
    }
};

int main(int argc, char** argv) {
    Solution sln;
    vector<int> nums = {1,0,2,3,0,4,5,0};
    sln.duplicateZeros(nums);

    for(vector<int>::iterator itr=nums.begin(); itr!=nums.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}