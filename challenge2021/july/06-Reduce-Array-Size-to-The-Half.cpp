#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
   int minSetSize(vector<int>& arr) {
      unordered_map <int, int> m;
      int n = arr.size();
      for(int i = 0; i < n; i++){
         m[arr[i]]++;
      }
      vector <int> temp;
      unordered_map <int, int> :: iterator it = m.begin();
      int sz = n;
      int ret = 0;
      while(it != m.end()){
         temp.push_back(it->second);
         it++;
      }
      sort(temp.rbegin(), temp.rend());
      for(int i = 0; i < temp.size(); i++){
         if(sz <= n / 2)break;
         ret++;
         sz -= temp[i];
      }
      return ret;
   }
};

int main(int argc, char **argv) {
    Solution sln;
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};

    int output = sln.minSetSize(arr);
    return 0;
}