#include<string>
using namespace std;
class Solution {
public:
    string res="";
    void fetPermutations(int n,int k,int status[],int d)
    {
        if(d==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(status[i]==0)
             {
                    res+=to_string(i);
                    status[i]=1;
                }
              //  return ;
            }
        }
        else
        {
            int t=factorial(d-1);
            int temp=k/t;
            if(k%t==0)
                ;
            else
            {
                temp++;
            }
            int count=0;
            for(int i=1;i<=n;i++)
            {
                if(status[i]==0)
                    count++;
                if(count==temp)
                {
                    res+=to_string(i);
                    status[i]=1;
                    break;
                }      
            }
            temp--;
            fetPermutations(n,k-temp*factorial(d-1),status,d-1);
        }   
    }
    int factorial(int n)
    {
        int res=1;
        for(int i=1;i<=n;i++)
            res*=i;
        return res;
    }
    string getPermutation(int n, int k) 
    {
        int status[100];
        for(int i=0;i<=n;i++)
        {
            status[i]=0;
        }
        fetPermutations(n,k,status,n);
        return res;
    }
};