#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        if (N == 0) return 0;

        int count = 0;
        vector<int> candy(N);
        DivideConque(ratings, candy, count, 0, N-1);
        return count;
    }

    void DivideConque(vector<int>& ratings, vector<int>& candy, int& count, int start, int end) {
        if (start == end) {candy[start]=1;count++;return;}
        int mid = start + (end-start)/2;
        DivideConque(ratings, candy, count, start,mid);
        DivideConque(ratings, candy, count, mid+1,end);
        
        for(int i=start;i<end;i++) {
            if(ratings[i]>ratings[i+1]){
                if (candy[i] <= candy[i+1]) {
                    count += candy[i+1]-candy[i]+1;
                    candy[i] = candy[i+1]+1;
                }
            } else if (ratings[i] < ratings[i+1]) {
                if (candy[i] >= candy[i+1]) {
                    count += candy[i]-candy[i+1]+1;
                    candy[i+1] = candy[i]+1;
                }
            }
        }
        for(int i=end-1;i>=start;i--) {
            if(ratings[i]>ratings[i+1]){
                if (candy[i] <= candy[i+1]) {
                    count += candy[i+1]-candy[i]+1;
                    candy[i] = candy[i+1]+1;
                }
            } else if (ratings[i] < ratings[i+1]) {
                if (candy[i] >= candy[i+1]) {
                    count += candy[i]-candy[i+1]+1;
                    candy[i+1] = candy[i]+1;
                }
            }
        }
    }
    //     vector<int> countSmaller_2(vector<int>& nums) 
    // {        
    //     int N = nums.size();
    //     if (N==0) return {};
        
    //     vector<int>sortedNums = nums;        
    //     vector<int>counts(N,0);
    //     DivideConque(nums,sortedNums, counts, 0, nums.size()-1);  
    //     return counts;
    // }
    
    // void DivideConque(vector<int>&nums, vector<int>&sortedNums, vector<int>&counts, int start, int end)
    // {
    //     if (start==end) return;
        
    //     int mid = start+(end-start)/2;
    //     DivideConque(nums, sortedNums, counts, start,mid);
    //     DivideConque(nums, sortedNums, counts, mid+1, end);
        
    //     for (int i=start; i<=mid; i++)
    //     {
    //         int val = nums[i];
    //         auto pos = lower_bound(sortedNums.begin()+mid+1, sortedNums.begin()+end+1,val);            
    //         counts[i] += pos-(sortedNums.begin()+mid+1);
    //     }
        
    //     sort(sortedNums.begin()+start,sortedNums.begin()+end+1);        
    // }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> ratings={1,2,87,87,87,2,1};
    int output = sln.candy(ratings);

    return 0;
}