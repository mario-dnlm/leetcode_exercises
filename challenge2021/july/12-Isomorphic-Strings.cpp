#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 1) return true;
        unordered_map<char, char> map_s2t;
        unordered_map<char, char> map_t2s;

        map_s2t.insert({s[0], t[0]});
        map_t2s.insert({t[0], s[0]});
        for(int i=1; i<s.size(); i++) {
            unordered_map<char, char>::const_iterator got_s2t = map_s2t.find(s[i]);
            unordered_map<char, char>::const_iterator got_t2s = map_t2s.find(t[i]);

            if (got_s2t == map_s2t.end() && got_t2s == map_t2s.end()) {
                map_s2t.insert({s[i], t[i]});
                map_t2s.insert({t[i], s[i]});
            } else if (got_s2t == map_s2t.end() || got_t2s == map_t2s.end()) {
                return false;
            } else if (got_s2t->second != t[i] || got_t2s->second != s[i] ){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string s = "badc";
    string t = "baba";
    bool output = sln.isIsomorphic(s,t);
    if (output) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}