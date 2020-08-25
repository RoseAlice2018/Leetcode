#include<iostream>
#include<algorithm>
using namespace std;
struct test
{
    int x,y;
}stu[10];
bool cmp(test a,test b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    else
    {
        return a.y>b.y;
    }
    
}
int main()
{
    sort(stu,stu+10,cmp);
}