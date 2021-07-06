#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;

        int i = 0;
        ans.push_back(0);
        
        for(int i =0; i<n; i++) {
            int base = pow(2, i);
            int j = ans.size()-1;
            while(j>=0) {
                ans.push_back(ans[j] + base);
                j--;
            } 
            
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int n = 3;
    vector<int> output = sln.grayCode(n);

    return 0;
}