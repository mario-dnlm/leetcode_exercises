#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum =0, length;
        for(vector<int>::iterator itr=matchsticks.begin(); itr!=matchsticks.end(); itr++) {
            sum += *itr;
        }
        cout << sum%4 << endl;
        if (sum%4 != 0) return false;
        length = sum/4;
        
        return false;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> matchsticks;
    bool output;
    matchsticks = {1,1,2,2,2};
    output = sln.makesquare(matchsticks);
    if (output) { printf("Output: true\n");} 
    else { printf("Output: false\n"); }

    return 0;
}