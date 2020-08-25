#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    char name[20];
    char ID[20];
    int grade;
};
bool cmp(node a,node b)
{
    return a.grade>b.grade;
}
int main()
{
    int N;
    scanf("%d",&N);
    node examp[N+2];
    for(int i=0;i<N;i++)
        scanf("%s %s %d",examp[i].name,examp[i].ID,&examp[i].grade);
    int bot,big;
    scanf("%d %d",&bot,&big);
    sort(examp,examp+N,cmp);
    int count=0;
    for(int i=0;i<N;i++)
    {
        if(examp[i].grade>=bot&&examp[i].grade<=big)
        {
            cout<<examp[i].name<<" "<<examp[i].ID<<endl;
            count++;
        }
                    
    }    
    if(count==0)
    {
        cout<<"NONE";
    }
    return 0;
}