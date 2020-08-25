#include<iostream>
#include<algorithm>
using namespace std;
struct  student
{
    /* data */
    char ID[10];
    char name[10];
    int grade;
};
bool cmp1(student a,student b)
{
    for(int i=0;i<6;i++)
    {
        if(a.ID[i]>b.ID[i])
            return 0;
        else if(a.ID[i]<b.ID[i])
            return 1;               
    }
}
bool cmp2(student a,student b)
{
    for(int i=0;a.name[i]!='\0'&&a.name[i]!='\0';i++)
    {
        if(a.name[i]>b.name[i])
            return 0;
        else if(a.name[i]<b.name[i])
            return 1;
    }
    for(int i=0;i<6;i++)
    {
        if(a.ID[i]>b.ID[i])
            return 0;
        else if(a.ID[i]<b.ID[i])
            return 1;               
    }
}
bool cmp3(student a,student b)
{
    if(a.grade>b.grade)
        return 0;
    else if(a.grade<b.grade)
        return 1;
    for(int i=0;i<6;i++)
    {
        if(a.ID[i]>b.ID[i])
            return 0;
        else if(a.ID[i]<b.ID[i])
            return 1;               
    }
}
int main()
{
    int N,C;
    cin>>N>>C;
    student example[N];
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %d",example[i].ID,example[i].name,&example[i].grade);
    }
    if(C==1)
    {
        sort(example,example+N,cmp1);
    }
    else if(C==2)
    {
        sort(example,example+N,cmp2);
    }
    else
    {
        sort(example,example+N,cmp3);
    }
    for(int i=0;i<N;i++)
    {
        printf("%s %s %d\n",example[i].ID,example[i].name,example[i].grade);
    }
    return 0;
}