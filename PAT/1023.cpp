#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string num;
    cin>>num;
    int res[60]={0};
    int count=0;
    for(int i=num.size()-1;i>=0;i--)
    {
        int temp=2*(num[i]-'0')+res[count];
        if(temp<10)
        {
            res[count]=temp;
        }
        else 
        {
            res[count]=temp-10;
            res[count+1]=1;
        }
        count++;
    }
    // check
    int nums[9]={0};
    for(int i=0;i<num.size();i++)
        nums[num[i]-'0']++;
    for(int i=0;i<count;i++)
    {
        nums[res[i]]--;
    }
    if(res[count]==1)
        nums[1]--;
    int tag=1;
    for(int i=0;i<9;i++)
    {
        if(nums[i]!=0)
        {
            printf("No\n");
            tag=0;
            break;
        }
    }
    if(tag)
        printf("Yes\n");
    if(res[count]==1)
        printf("1");
    for(int i=count-1;i>=0;i--)
        printf("%d",res[i]);
    return 0;
}