#include <iostream>
#include <chrono>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int M = s1.size();
        const int N = s2.size();

        // create a 2D table to store solutions of subproblems. s3[i][j] will be true if s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1]
        bool IL_map[M+1][N+1];
        memset(IL_map, false, (M+1)*(N+1));
        //vector<vector<bool>> IL_map(M, vector<bool> (N, false));
        
        // s3 can be interleaving of s1 and s2 only if the sum of length of A & B is equal
        if (M + N != s3.size()) {
            return false;
        }
        else if (s3.size() == 0) {
            return true;
        }
        else if (M == 0) {
            for (int j = 0; j < N; j++) {
                if (s2[j] != s3[j]) {
                    return false;
                }
            }
            return true;
        }
        else if (N == 0) {
            for (int i=0; i < M; i++) {
                if (s1[i] != s3[i]) {
                    return false;
                }
            }
            return true;
        }

        // Process all characters of s1 and s2
        for (int i = 0; i <= M; i++) {
            for (int j =0; j <= N; j++) {
                // two empty strings have an empty string as interleaving
                if (i == 0 && j == 0) {
                    IL_map[i][j] = true;
                }
                else if (i == 0) {  // A is empty
                    if (s2[j-1] == s3[j-1]) {
                        IL_map[i][j] = IL_map[i][j-1];
                    }
                }
                else if (j == 0) { // B is empty
                    if (s1[i-1] == s3[i-1]) {
                        IL_map[i][j] = IL_map[i-1][j];
                    }
                }

                // Current character of s3 mateches with current character of A, but doesnt match with current character of B
                else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) {
                    IL_map[i][j] = IL_map[i-1][j];
                }
                else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    IL_map[i][j] = IL_map[i][j-1];
                }
                else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    IL_map[i][j] = IL_map[i-1][j] || IL_map[i][j-1];
                }
            }
        }
        return IL_map[M][N];
    }
    
};

int main(int argc, char** argv) {
    cout << "Solution to 02 Interleaving String\n";
    cout << "=========================\n";

    Solution sln;
    
    string s1 = "aa";
    string s2 = "ab";
    string s3 = "abaa";
    
    auto start = chrono::steady_clock::now();
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    if (sln.isInterleave(s1,s2,s3)) { cout << "Output: true\n";}
    else { cout << "Output: false\n";}

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    return 0;
}