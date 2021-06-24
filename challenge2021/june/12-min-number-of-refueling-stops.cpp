#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int N = stations.size();
        if (N == 0) { return (startFuel >= target) ? 0 : -1; }
        if (startFuel >= target) { return 0; }

        int i = N-1;
        int current_pos = 0;
        int current_fuel = startFuel;
        queue<int> myqueue;
        int pre_pos = 0;
        int pre_fuel = 0;

        while(i >= 0) {
            if ( current_fuel + current_pos >= stations[i][0] ) {
                // car can reach the station[i]
                myqueue.push(i);
                
                current_fuel = current_fuel - (stations[i][0] - current_pos) + stations[i][1];
                current_pos = stations[i][0];

                if (current_pos + current_fuel >= target) {
                    return myqueue.size();
                } else if (i == N-1) {
                    // pop index i
                    myqueue.pop();
                    current_pos = stations[myqueue.front()][0];
                    
                }
                // search for next station (i,...,N-1]
                i = N - 1;
                 
            } else {
                // car can't reach the station[i]
                //cout << myqueue.size() << endl;
                i--;
                if ( current_pos <= stations[i][0] ) {
                    
                }

                if (stations[i][0] <= current_pos) {
                    // go back to previous move
                    if (!myqueue.empty()) { myqueue.pop(); }

                }
                
            }
        }
        
        return (current_pos + current_fuel >= target) ? myqueue.size() : -1;
        // return -1;
    }

};

int main(int argc, char **argv) {
    Solution sln;
    int target;
    int startFuel;
    vector<vector<int>> stations;
    int output;

    // target = 100;
    // startFuel = 10;
    // stations = {{10,60}, {20,30},{30,30},{60,40}};
    // output = sln.minRefuelStops(target, startFuel, stations);
    // printf("Output : %d\n", output);

    // target = 1;
    // startFuel = 1;
    // stations = {};
    // output = sln.minRefuelStops(target, startFuel, stations);
    // printf("Output : %d\n", output);

    // target = 999;
    // startFuel = 1000;
    // stations = {{5,100}, {997,100}, {998,100}};
    // output = sln.minRefuelStops(target, startFuel, stations);
    // printf("Output : %d\n", output);

    target = 100;
    startFuel = 25;
    stations = {{25,25}, {50,25}, {75,25}};
    output = sln.minRefuelStops(target, startFuel, stations);
    printf("Output : %d\n", output);

    return 0;
}