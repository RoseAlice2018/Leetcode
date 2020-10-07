#include<string>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
         n=n%s.size();
        if(n==0)
            return s;
        s=s.substr(n,s.size()-1)+s.substr(0,n);
        return s;
    }
};