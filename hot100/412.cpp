#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string c1="Fizz";
    string c2="Buzz";
    string c3="FizzBuzz";
    vector<string> fizzBuzz(int n) 
    {
        vector<string>  res;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&&i%5==0)
            {
                res.push_back(c3);
            }
            else if(i%3==0)
            {
                res.push_back(c1);
            }
            else if(i%5==0)
            {
                res.push_back(c2);
            }
            else
            {
                string temp=to_string(i);
                res.push_back(temp);
            }
            
        }
        return res;
    }
};