/*
实现带有期限的作业排序问题的优化算法，包括算法5.4和算法5.5。
举例：作业数量n=10，作业对应的效益值和完成期限分别为 {10,9,8,7,6,5,4,3,2,1}和{9,7,5,6,4,7,4,2,1,6}。
延展题目（optional）：随机生成n=10000的作业排序问题，测量算法5.4和算法5.5的运行时间，体会不同算法的效率。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n=10;
struct work
{
    int p;//效益值
    int d;//deadline
};
vector<int> D;
work J[20];
void JS(int n,work test[])
{
   int i,k,r;
   k=1;
   J[0]=test[0];
   for(int i=2;i<n;i++)
   {
       r=k;
       while(J[r].d>test[i].d&&J[r].d!=r)
       {
           r=r-1;
       }
       if(J[r].d>=test[i].d&&test[i].d>r)
       {
           for(int m=k;m>r+1;m--)
           {
               J[m+1]=J[m];
           }
           J[r+1]=test[i];
           k=k+1;
       }
   }
}
void FJS(int D[],int n,int b ,int F[],int P[,int k)
{
    for(int i=0;i<=n;i++)
    {
        F[i]=i;
        P[i]=i;
    }
    k=0;
    for(int i=1;i<=n;i++)
    {
        j=find(min(n,D[i]));
        if(F[j]!=0)
        {
            k=k+1;
            J[k]=i;
            l=find(F(j)-1);
            UNION(i,j);
            F(j)=F(i);
        }
    }

}
bool cmp(work a,work b)
{
    return a.p>=b.p;
}
int main()
{
    work test[10]={{10,9},{9,7},{8,5},{7,6},{6,4},{5,7},{4,4},{3,2},{2,1},{1,6}};
    sort(test,test+10,cmp);
    JS(10,test);
    for(int i=0;i<20;i++)
    {
        if(J[i].p&&J[i].d)
        {
            cout<<J[i].p<<" "<<J[i].d<<endl;
        }
    }
    return 0;
}