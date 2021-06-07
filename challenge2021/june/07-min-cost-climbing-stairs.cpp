#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <cstring>

using namespace std;
 /** 
  * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
  * Once you pay the cost, you can either climb one or two steps.
 *  You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 * 
 * */

class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) { return 0; }
        else if(cost.size() == 2) { return min(cost[0], cost[1]); }

        const int N = cost.size();
        int dp[N + 1];
        // memset(dp, 0, N * sizeof(int));
        dp[N] = 0;
        dp[N-1] = 0;
        
        for(int i = N-2; i >= 0; i--) {
            dp[i] = min(cost[i] + dp[i+1], cost[i+1] + dp[i+2]);
        }
        return dp[0];
    }
};


int main(int argc, char** argv) {

    Solution sln;
    // vector<int> cost = {10,15,20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    int output;
    output = sln.minCostClimbingStairs(cost);
    printf("Output: %d\n", output);    
    return 0;
}