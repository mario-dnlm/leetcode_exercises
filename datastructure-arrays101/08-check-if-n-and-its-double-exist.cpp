#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkItExist(vector<int>& arr) {
        vector<int> arr2(arr);
        sort(arr2.begin(),arr2.end());
        int i=0;

        while(i < arr2.size()-1) {
            // find if double of arr[i] exists
            if (arr2[i] >= 0) {
                for (int j=i+1; j<arr2.size() && arr2[j] <= 2*arr2[i]; j++)
                {
                    if (arr2[j] == 2*arr2[i]) { return true; }
                }
            } else {
                for (int j=i-1; j >=0 && arr2[j] >= 2*arr2[i]; j--) {
                    if (arr2[j] == 2*arr2[i]) { return true; }
                }
            }
            i++;
        }         
        return false;
    }
};

int main(int argc, char** argv) {
    Solution sln;
    vector<int> arr = {-10,12,-20,-8,15};
    bool flag = sln.checkItExist(arr);
    if (flag) { cout << "true\n"; }
    else { cout << "false\n"; }

    return 0;
}