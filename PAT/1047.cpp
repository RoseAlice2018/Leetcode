#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct students
{
    char name[5];
    int c;
};
struct  courses
{
    queue<string> names;
};
bool cmp(string a,string b)
{
    int minsize=min(a.size(),b.size());
    for(int i=0;i<minsize;i++)
    {
        if(a[i]<b[i])
            return 1;
        else if(a[i]>b[i])
            return 0;
        
    }
    return 0;
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int numberofcourse[K+2];
    for(int i=0;i<K+2;i++)
        numberofcourse[i]=0;
    students st[N];
    courses course[K+2];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d",st[i].name,&st[i].c);
        for(int j=0;j<st[i].c;j++)
        {
            int temp;
            scanf("%d",&temp);
            numberofcourse[temp]++;
            course[temp].names.push(st[i].name);
        }
    }
    for(int i=0;i<K;i++)
    {
        printf("%d %d\n",i+1,numberofcourse[i+1]);
        string t[N];
        int count=0;
        while (!course[i+1].names.empty())
        {
            t[count++]=course[i+1].names.front();
            course[i+1].names.pop();
        } 
        sort(t,t+count,cmp);
        for(int j=0;j<count;j++)
            cout<<t[j]<<endl;
    }
    
    
    return 0;
}