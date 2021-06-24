#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<string> generateParenthesis(int n) {
    //     int left = 1;
    //     vector<string> output;
    //     string ref(n, '(');
    //     ref.append(string(n,')'));
    //     output.push_back(ref);
    //     // for(int i=0;i<n;i++) {  ref[i] = '(';}
    //     // for(int i=0;i<n;i++) {  ref[n+i] = ')';}
        
    //     while(left < n) {
    //         string tempStr(ref);
    //         for(int right = n; right < n+n-1; right++){
    //             //string tempStr(tempStr1);
    //             char tmpC = tempStr[left];
    //             tempStr[left] = tempStr[right]; 
    //             tempStr[right] = tmpC;
    //             output.push_back(tempStr);
    //         }                
    //         left++;

    //     }
    //     return output;
    // }
    vector<string> generateParenthesis(int n) {

    }
    void _printParenthesis(int pos, int n,
                        int open, int close)
    {
        static char str[MAX_SIZE];   
        
        if (close == n)
        {
            cout << str << endl;
            return;
        }
        else
        {
            if (open > close)
            {
                str[pos] = '}';
                _printParenthesis(pos + 1, n, open,
                                close + 1);
            }
            
            if (open < n)
            {
                str[pos] = '{';
                _printParenthesis(pos + 1, n,
                                open + 1, close);
            }
        }
    }
 
    // Wrapper over _printParenthesis()
    void printParenthesis(int n)
    {
        if (n > 0)
            _printParenthesis(0, n, 0, 0);
            
        return;
    }   
    

};

int main(int argc, char **argv) {
    Solution sln;
    int n = 4;
    vector<string> output = sln.generateParenthesis(n);    

    return 0;
}