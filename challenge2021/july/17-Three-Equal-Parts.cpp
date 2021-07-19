#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Solution {
public:
   vector<int> threeEqualParts(vector<int>& A) 
    {
        vector<int> rets;
        
        int count = 0;
        for (auto x: A)
            if (x==1) count++;
        if (count%3!=0) return {-1,-1};
        if (count==0) return {0,(int)(A.size()-1)};
        count/=3;
        
        int j = A.size();
        while (count)
        {
            j--;
            if (A[j]==1) count--;
        }
        
        int i = 0;
        while (A[i]==0) i++;
        int k = j;
        while (k<A.size() && A[i]==A[k])
        {
            i++;
            k++;
        }
        if (k!=A.size()) return {-1,-1};
        rets.push_back(i-1);
        
        while (A[i]==0) i++;
        k = j;
        while (k<A.size() && A[i]==A[k])
        {
            i++;
            k++;
        }
        if (k!=A.size()) return {-1,-1};
        rets.push_back(i);
        
        return rets;
    }


    vector<int> threeEqualParts_old2(vector<int>& arr) {
        const int N = arr.size();
        vector<int> ans;
        
        if (N < 3) { 
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int total_count=0;
        for(int k=0; k<N; k++) { if (arr[k] > 0) { total_count++;} }
        
        if (total_count==0) {
            ans.push_back(0);
            ans.push_back(N-1);
            return ans;
        }
        if (total_count%3!=0) { 
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int i = 0, j=N-1;
        // int count_left=0, count_mid=0, count_right=0;
        int count_target = total_count/3;
        int count=0;
        while (count < count_target) {
            if (arr[i] != 0) { count++; }
            i++;
        }
        i--;
        count = 0;
        int zero_padding = 0;
        while (count < count_target) {
            if (count==0 && arr[j]==0) { zero_padding++;}
            if (arr[j] != 0) { count++;}
            j--;
        }
        j++;
        int zero_count =0;
        while(arr[j-1]==0) {
            j--;
        }
        while(zero_padding>0) {
            j++;
            i++;
            zero_padding--;
        }

        int Left=0, Mid=0, Right=0;
        for(int k=0;k<i+1;k++) { Left=Left*2+arr[k];}
        for(int k=i+1;k<j;k++) { Mid=Mid*2+arr[k];}
        for(int k=j;k<N;k++) { Right=Right*2+arr[k];}
        if(Left==Mid && Mid==Right) {
            ans.push_back(i);
            ans.push_back(j);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }

    vector<int> threeEqualParts_old(vector<int>& arr) {
        const int N = arr.size();
        vector<int> ans;
        int i=0;
        int j=N-1;
        
        if (N < 3) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        long Left = arr[i];
        long Right = arr[j];
        long Mid = 0;
        for (int k=i+1; k<j; k++) { Mid = Mid*2+arr[k]; }

        while(i+1<j) {
            if (Left==Mid && Mid==Right) {
                break;
            } else if (Mid < Left && Mid < Right) {
                i = -1;
                j = -1;
                break;
            } else if (Left >= Right) {
                // fix i, change j
                j--;
                if (i+1==j) { i=-1; j=-1; break;} 
                if(arr[j]>0) { 
                    Right += pow(2,N-j-1); 
                    Mid -= arr[j]; 
                }
                Mid = Mid/2.0;
            } else {//if (Right >= Left) {
                // fix j, change i
                i++;
                if (i+1==j) { i=-1; j=-1; break;} 
                Left = Left*2 + arr[i];
                if (arr[i] > 0) {
                    Mid -= pow(2,j-i-1);
                }
            }
        }
        ans.push_back(i);
        ans.push_back(j);
        return ans; 
    }
};

int main(int argc, char ** argv) {
    Solution sln;
    // vector<int> arr = {1,0,1,0,1};
    // // vector<int> arr = {1,1,0,0,1};
    // vector<int> arr = {0,1,0,1,1};
    // vector<int> arr = {1,0,0};
    vector<int> arr = {1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0};
    
    vector<int> output = sln.threeEqualParts(arr);
    return 0;
}