#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> table(26);
        for (int i=0; i < s.size(); i++) {
            table[s[i]-'a'].push_back(i);
        }

        return 0;
    }
};


int main(int argc, char **argv) {
    Solution sln;
    string s = "abcde";
    vector<string> words = {"a","bb","acd","ace"};
    int output;

    output = sln.numMatchingSubseq(s, words);

    return 0;
}