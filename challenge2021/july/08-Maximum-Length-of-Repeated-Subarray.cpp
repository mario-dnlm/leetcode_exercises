#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int m = A.size();
        int n = B.size();
        A.insert(A.begin(), 0);
        B.insert(B.begin(), 0);
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(int)*(m+1)*(n+1));
        int ret = 0;

        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                dp[i][j] = A[i]==B[j]? dp[i-1][j-1]+1 : 0;
                ret = max(ret, dp[i][j]);
            }
        return ret;
    }
};


int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    int output = sln.findLength(nums1, nums2);

    return 0;
}