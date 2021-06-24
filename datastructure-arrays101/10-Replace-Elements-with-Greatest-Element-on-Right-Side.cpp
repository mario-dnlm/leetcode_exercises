#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr);
        const int N = arr.size();
        int max_item = arr[N-1];
        
        ans[N-1] = -1;
        
        for(int i=N-2; i >= 0; i--) {
            if (arr[i+1] > max_item) { max_item = arr[i+1]; }
            ans[i] = max_item;
        }
        return ans;
    }
};

int main(int argc, char **argv) {

    return 0;
}