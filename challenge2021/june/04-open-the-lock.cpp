#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <math.h>
#include <algorithm> // std::sort

using namespace std;

class Solution
{
    public:
    int openLock(vector<string>& deadends, string target) {
        
        string mywheels = "3077";
        const int BASE = 10;

        // Testing the bitwise wheel distance
        if ( false ) {
            string a = "1234";
            string b = "8901";
            for (int i =0; i <a.size(); i++) {
                cout << "i: " << i << " | " << int((a[i]-b[i]+10)%10) << endl;
            }
        }
        
        // Find minimum node without checking the deadends set
        int minDis = 0;

        int distances[4];
        // int distances2[4];
        for(int i=0; i<target.size(); i++) {
            distances[i] = int(target[i] - mywheels[i]);
            //distances2[i] = BASE - int(target[i] - mywheels[i]);
            if (distances[i] < -5) { distances[i] = (distances[i] + BASE)% BASE; }
            else if (distances[i] > 5) { distances[i] -= BASE; }
            minDis += abs(distances[i]);
        }
        return minDis;


        if (false) {
            cout << "\ndeadends: ";
            for (vector<string>::iterator it = deadends.begin(); it!=deadends.end(); it++) {
                cout << *it << ", ";
                if (*it == mywheels) {
                    return -1;
                }
            }
        }
        


        return -999; // dump value
    }
    
};

int main(int argc, char **argv) {
    cout << "\"Open the Lock\"\n";

    auto start = std::chrono::system_clock::now();
    // Some computation here
        Solution sln;
        vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
        string target = "0202";
        int output = sln.openLock(deadends, target);
        cout << "\nOutput: " << output << endl;

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;


    return 0;
}
