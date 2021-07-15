#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string order, string str) {
        int alphabet_count [26] = {};
        string ans = "";

        for (int i=0; i<str.size(); i++) {
            alphabet_count[str[i]-'a']++;
        }

        for (int i=0; i<order.size(); i++) {
            int N = alphabet_count[order[i]-'a'];
            if (N != 0) {
                ans.append(N, order[i]);
                alphabet_count[order[i]-'a']=0;
            }
        }
        for (int i=0; i<26; i++) {
            if (alphabet_count[i] != 0) {
                ans.append(alphabet_count[i], 'a'+i);
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string order = "cba";
    string str = "abcddcba";

    string output = sln.customSortString(order, str);
    cout << "Output: " << output << endl;
    return 0;
}