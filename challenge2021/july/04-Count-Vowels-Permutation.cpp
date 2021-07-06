#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    int countVowelPermutation(int n) {
        if (n==1) return 5;
        const int MOD = 1e9+7;

        vector<long> count(5,1);
        for(int i=1; i < n; i++) {
            vector<long> tmp(5,0);

            for(int j=0; j<5; j++) {
                switch(j){
                    case 0:
                        tmp[1] = (tmp[1]>= MOD-count[j]) ? tmp[1]+count[j]-MOD : tmp[1]+count[j];
                        // tmp[1]+= count[j];
                        break;
                    case 1: 
                        tmp[0] = (tmp[0]>= MOD-count[j]) ? tmp[0]+count[j]-MOD : tmp[0]+count[j];
                        tmp[2] = (tmp[2]>= MOD-count[j]) ? tmp[2]+count[j]-MOD : tmp[2]+count[j];
                        // tmp[0]+=count[j]; 
                        // tmp[2]+=count[j];
                        break;
                    case 2:
                        tmp[0] = (tmp[0]>= MOD-count[j]) ? tmp[0]+count[j]-MOD : tmp[0]+count[j];
                        tmp[1] = (tmp[1]>= MOD-count[j]) ? tmp[1]+count[j]-MOD : tmp[1]+count[j];
                        tmp[3] = (tmp[3]>= MOD-count[j]) ? tmp[3]+count[j]-MOD : tmp[3]+count[j];
                        tmp[4] = (tmp[4]>= MOD-count[j]) ? tmp[4]+count[j]-MOD : tmp[4]+count[j];
                        // tmp[0]+=count[j]; 
                        // tmp[1]+=count[j]; 
                        // tmp[3]+=count[j]; 
                        // tmp[4]+=count[j];
                        break;
                    case 3:
                        tmp[2] = (tmp[2]>= MOD-count[j]) ? tmp[2]+count[j]-MOD : tmp[2]+count[j];
                        tmp[4] = (tmp[4]>= MOD-count[j]) ? tmp[4]+count[j]-MOD : tmp[4]+count[j];
                        // tmp[2]+=count[j]; 
                        // tmp[4]+=count[j];
                        break;
                    case 4:
                        tmp[0] = (tmp[0]>= MOD-count[j]) ? tmp[0]+count[j]-MOD : tmp[0]+count[j];
                        // tmp[0]+=count[j];
                        break;
                }
            }
            count=tmp;
            for(int j=0;j<5;j++) {
                count[j]=count[j]%MOD;
            }
            // int ans=0;
            // for(int j=0;j<5;j++){
            //     ans = (ans>=MOD-count[j])? ans+count[j]-MOD : ans+count[j];
            // }
            // printf("i:%d = %d\n", i,ans);
        }
        int ans=0;
        for(int j=0;j<5;j++){
            ans = (ans>=MOD-count[j])? ans+count[j]-MOD : ans+count[j];
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    Solution sln;
    int n = 144;
    int output = sln.countVowelPermutation(n);
    printf("Input: %d | \t Output: %d\n", n, output);
    return 0;
}