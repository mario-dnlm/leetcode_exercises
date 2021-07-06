#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        const int N = arr.size();
        int start = 0;
        int end = N-1;
        int mid = start + (end - start)/2;
        
        while (end-start>1) {
            if (arr[mid] > x) {
                end = mid;
                mid = start + (end-start)/2;
            } else if (arr[mid] < x) {
                start = mid;
                mid = start + (end-start)/2;
            } else {
                // found
                start = mid;
                end = mid;
            }
        }
        if(x-arr[start] <= arr[end]-x) {
            mid = start;
        } else {
            mid = end;
        }
        ans.push_back(arr[mid]);
        int left = mid-1, right = mid+1;
        for(int count =1; count < k; count++) {
            if(left >= 0 && right < N) {
                if ( x-arr[left] <= arr[right]-x) {
                    ans.push_back(arr[left--]);
                } else {
                    ans.push_back(arr[right++]);
                }
            } else if (left < 0) {
                ans.push_back(arr[right++]);
            } else {
                ans.push_back(arr[left--]);
            }
        
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> arr = {1,2,3,4,5};
    vector<int> arr = {1,3,5,7,9};
    int k=4;
    int x=4;

    vector<int> output = sln.findClosestElements(arr,k,x);

    return 0;
}