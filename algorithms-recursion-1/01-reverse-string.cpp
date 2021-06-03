#include <iostream>
#include <chrono>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// Write a function that reverses a string. The input string is given as an array of characters s.
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};


int main(int argc, char** argv) {
    Solution sln;
    vector<char> s = {'h','e','l','l','o'};
    sln.reverseString(s);

    return 0;
}