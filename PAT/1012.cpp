#include<iostream>
#include<algorithm>
using namespace std;
struct student
{
    char ID[10];
    int C;
    int M;
    int E;
    int A;
    int rank[4];
};
bool cmpC(student a,student b)
{
    return a.C>b.C;
}
bool cmpM(student a,student b)
{
    return a.M>b.M;
}
bool cmpE(student a,student b)
{
    return a.E>b.E;
}
bool cmpA(student a,student b)
{
    return a.A>b.A;
}
bool equal(char s1[],char s2[])
{
    for(int i=0;i<6;i++)
    {
        if(s1[i]!=s2[i])
            return false;
    }
        
    return true;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    student total_[100];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d %d %d",total_[i].ID,&total_[i].C,&total_[i].M,&total_[i].E);
        total_[i].A=(total_[i].C+total_[i].M+total_[i].E)/3;
    }
    char course[4]={'E','M','C','A'};
  
     sort(total_,total_+N,cmpE);
    for(int i=0;i<N;i++)
        total_[i].rank[0]=i;  
    sort(total_,total_+N,cmpM);
    for(int i=0;i<N;i++)
        total_[i].rank[1]=i;
  
     sort(total_,total_+N,cmpC);
    for(int i=0;i<N;i++)
        total_[i].rank[2]=i;
    sort(total_,total_+N,cmpA);
    for(int i=0;i<N;i++)
        total_[i].rank[3]=i;
    for(int i=0;i<M;i++)
    {
        char ID_Check[10];
        scanf("%s",ID_Check);
        int tag=1;
        for(int j=0;j<N;j++)
        {
            if(equal(ID_Check,total_[j].ID))
            {
                int maxgrade=N+2,maxcourse=0;
                for(int m=0;m<4;m++)
                {
                    if(total_[j].rank[m]<=maxgrade)
                    {
                        tag=0;
                        maxcourse=m;
                        maxgrade=total_[j].rank[m];
                    }
                }
                if(!tag)
                {
                    printf("%d %c\n",maxgrade+1,course[maxcourse]);
                }
            }
        }
        if(tag)
        {
            printf("N/A");
        }
    }
    return 0;
}