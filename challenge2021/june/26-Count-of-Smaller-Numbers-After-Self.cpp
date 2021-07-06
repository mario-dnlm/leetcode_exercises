#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


// Least Significant Bit of i
#define LSB(i) ((i) & -(i))

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#define SIZE 20001
class Solution {
private:
    int tree_[SIZE];
    int len2;
public:
    // Returns the sum of the first i elements (indices 0 to i)
    // Equivalent to range_sum(0, i)
    int prefix_sum(int i)
    {
        int sum = this->tree_[0];
        for (; i != 0; i -= LSB(i))
            sum += this->tree_[i];
        return sum;
    }

    // Add delta to element with index i (zero-based)
    void add(int i)
    {
        if (i == 0){
            this->tree_[0] += 1;
            return;
        }
        for (; i < SIZE; i+= LSB(i))
            this->tree_[i] += 1;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        auto len = nums.size();
        memset(this->tree_,0,SIZE*sizeof(int));
        vector<int> counts(len);
        while (len--) {
            auto x = nums[len]+10001;
            counts[len] = this->prefix_sum(x-1);
            this->add(x);
        }
        return counts;
    }
};


class Solution_1 {    
public:

    vector<int> countSmaller_overtimelimit(vector<int>& nums) 
    {        
        const int N = nums.size();
        if (N==0) return {};
        
        vector<int>sortedNums; // = nums;        
        vector<int>counts(N,0);
        
        for (int i=N-1; i>=0; i--) {
            int val = nums[i];
            auto pos = lower_bound(sortedNums.begin(), sortedNums.end(),val);            
            counts[i] += pos-(sortedNums.begin());
            sortedNums.insert(pos, val);
        }
        return counts;
    }

    vector<int> countSmaller_2(vector<int>& nums) 
    {        
        int N = nums.size();
        if (N==0) return {};
        
        vector<int>sortedNums = nums;        
        vector<int>counts(N,0);
        DivideConque(nums,sortedNums, counts, 0, nums.size()-1);  
        return counts;
    }
    
    void DivideConque(vector<int>&nums, vector<int>&sortedNums, vector<int>&counts, int start, int end)
    {
        if (start==end) return;
        
        int mid = start+(end-start)/2;
        DivideConque(nums, sortedNums, counts, start,mid);
        DivideConque(nums, sortedNums, counts, mid+1, end);
        
        for (int i=start; i<=mid; i++)
        {
            int val = nums[i];
            auto pos = lower_bound(sortedNums.begin()+mid+1, sortedNums.begin()+end+1,val);            
            counts[i] += pos-(sortedNums.begin()+mid+1);
        }
        
        sort(sortedNums.begin()+start,sortedNums.begin()+end+1);        
    }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> nums= {10,5,7,3,2,4,6,1};
    vector<int> output = sln.countSmaller(nums);

    return 0;
}


// sample 72 ms submission
/** 
 * 
 * 
 * int bit[20001];
int speedup = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        fill(begin(bit), end(bit), 0);
        vector<int> res(nums.size());
        for (int i = size(nums)-1; i >= 0; --i) {
            int cnt = 0;
            for (int p = nums[i]+9999; p >= 0; p = (p & (p + 1)) - 1) cnt += bit[p];
            res[i] = cnt;
            for (int p = nums[i]+10000; p <= 20000; p = p | (p + 1)) ++bit[p];
        }
        return res;
    }
};
 * 
 * 
*/