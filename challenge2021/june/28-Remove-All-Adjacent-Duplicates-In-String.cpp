#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        
        while (s[0] == s[1] && s.size()>=2) {
            s.erase(0,2);    
        }
        if (s.size() < 2) return s;
        
        int i=s.size()-2;
        while (i>=0) {
            if(s[i+1] == s[i]) {
                s.erase(i,2);
                i = (i < s.size()-2)? i : i-1;
            } else {
                i-=1;
            }
        }
        return s;

        // string s2 = removeDuplicates(string(s, 1, s.size()-1));
        // if (s2.size() < 1) return string(s,0,1);
        // else if (s2[0] == s[0]) {
        //     s2.erase(0,1);
        //     return s2;
        // }
        // else return string(s,0,1).append(s2);

    }
};

int main(int argc, char **argv) {
    Solution sln;
    // string s = "abbaca";
    string s = "azxxzy";
    string output = sln.removeDuplicates(s);

    return 0;
}