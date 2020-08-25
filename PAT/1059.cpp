#include<iostream>
#include<map>
#include<math.h>
#include<vector>
using namespace std;
bool isprime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    long n;
    scanf("%d",&n);
    printf("%d=",n);
    if(n==1)
    {
        printf("1");
        return 0;
    }
    vector<int> prime;
    for(int i=2;i<1e5;i++)
    {
        if(isprime(i))
            prime.push_back(i);
    }
    map<int,int> res;
    for(int i=0;i<prime.size();i++)
    {
        while(n%prime[i]==0)
        {
            ++res[prime[i]];
            n=n/prime[i];
        }
        if(n==1)
            break;
    }
    //output 
    for(auto i=res.cbegin();i!=res.cend();++i)
    {
        if(i!=res.cbegin())
            printf("*");
        printf("%d",i->first);
        if(i->second>1)
            printf("^%d",i->second);
    }
    

    return 0;
}