#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        int count = 0;
        sort(expected.begin(), expected.end());

        for(int i=0;i < heights.size(); i++) {
            if(expected[i] != heights[i]) {
                count++;
            }
        }    
        return count;    
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> heights = {1,2,3,4,5};

    int output = sln.heightChecker(heights);

    return 0;
}