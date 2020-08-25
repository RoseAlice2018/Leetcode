#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    while (K--)
    {
        int A[N],t=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        stack<int> s;
        bool res=true;
        for(int i=0;i<N&&res;i++)
        {
            if(s.empty()||s.top()<A[i])
            {
                for(int j=t+1;j<=A[i]&&s.size()<M;j++)
                    s.push(j);
                t=s.empty()?0:s.top();
                if(t==A[i])
                    s.pop();
                else
                    res=false;                
            }
            else if(s.top()==A[i])
                s.pop();
            else if(s.top()>A[i])
                res=false;
        }
        if(res==true)
            printf("YES\n");
        else
        {
            printf("NO\n");
        }
        
    }
    
    return 0;
}