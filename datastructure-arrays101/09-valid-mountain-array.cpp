#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) { return false; }
        bool isRising = true;
        if (arr[0] >= arr[1]) { return false; }
        int i=2, p = arr[1];
        while (i < arr.size()) {
            if (arr[i] == p) { return false; }
            else if (arr[i] > p) {
                if (!isRising) { return false; }
            } else {
                if (isRising) { isRising = false;}
            }
            p = arr[i++];
        }
        return !isRising;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> arr = {0,1,2,4,2,1};
    if (sln.validMountainArray(arr)) {
        cout << "Output : true\n";
    } else {
        cout << "Output : false\n";
    }

    return 0;
}