#include<algorithm>
#include<initializer_list>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
    private:
        int cal(int n)
        {
            int sum=0;
            while (n>0)
            {
                int temp=n%10;
                sum+=(temp*temp);
                n=(n-temp)/10;
            }
            return sum;            
        }
public:
    bool isHappy(int n) 
    {
        unordered_map<int,bool> seen;
        while(1)
        {
            int temp=cal(n);
            if(temp==1)
                return true;
            else if(seen[temp])
                return false;
            n=temp;
            seen[temp]=true;
        }
        return false;
    }   
};