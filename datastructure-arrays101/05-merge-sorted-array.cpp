#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin(), nums1.begin()+m);

        int i3 = 0, i2 = 0;
        while (i3 < m || i2 < n) {
            if (i3 < m && i2 < n) {
                if (nums3[i3] < nums2[i2]) { nums1[i3 + i2] = nums3[i3];    i3++;}
                else { nums1[i3 + i2] = nums2[i2];  i2++;}
                
            } else if (i3 < m) { nums1[i3 + i2] = nums3[i3];    i3++;}
            else { nums1[i3 + i2] = nums2[i2];  i2++; }
        }

    }
};

int main(int argc, char **argv) {
    
    Solution sln;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    return 0;
}