#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> VI;

class Solution {
private:
    unordered_map<int,int>Father;

    int FindSet(int x) {
        if (x != Father[x]) {
            Father[x] = FindSet(Father[x]);
        }
        return Father[x];
    }
    void Union(int x, int y) {
        x=FindSet(x);
        y=FindSet(y);
        if (x<=y) {
            Father[y]=x;
        } else {
            Father[x]=y;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i=0; i<edges.size(); i++) {
            Father[edges[i][0]] = edges[i][0];
            Father[edges[i][1]] = edges[i][1];
        }
        for (int i=0; i<edges.size(); i++) {
            if (FindSet(edges[i][0])==FindSet(edges[i][1])) {
                return edges[i];
            } else {
                Union(edges[i][0], edges[i][1]);
            }
        }
        return edges[0];
    }
};

int main(int argc, char **argv){
    Solution sln;
    // vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> edges = {{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}};
    vector<int> output = sln.findRedundantConnection(edges);
    printf("Output: [%d,%d]\n", output[0], output[1]);
    return 0;
}