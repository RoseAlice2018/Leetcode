#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
struct Wealthy_man
{
    char name[20];
    int age;
    int money;
};
bool cmp(Wealthy_man a, Wealthy_man b)
{
    if(a.money!=b.money)
    {
        return a.money>b.money;
    }
    else if(a.age!=b.age)
    {
        return a.age<b.age;
    }
    else 
    {
        if(strcmp(a.name,b.name)<0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
void query(Wealthy_man check[],int n)
{
    int k,age_min,age_max;
    scanf("%d %d %d",&k,&age_min,&age_max);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count==k)
        {
            break;
        }
        if(check[i].age>=age_min&&check[i].age<=age_max)
        {
            count++;
            printf("%s %d %d\n",check[i].name,check[i].age,check[i].money);
        }
    }
    if(count==0)
    {
        printf("None");
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    Wealthy_man check[10+2];
    for(int i=0;i<n;i++)
    {
        cin>>check[i].name>>check[i].age>>check[i].money;
    }
    sort(check,check+n,cmp);
    for(int i=1;i<=m;i++)
    {
        printf("Case #%d:\n",i);
        query(check,n);
    }

    return 0;
}