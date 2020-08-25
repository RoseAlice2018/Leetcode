/*
已知一个长度为n的整数序列，设计分治算法，求和最大的连续子序列。
举例：输入1,1,2,-10,3,-1,5,8,11,-20,1,3,2输出为3,-1,5,8,11，和该序列的和：26
*/
#include<iostream>
#include<vector>
using namespace std;
//num数组用来存储待检测的数组
int num[100]={1,-1,2};
//left1表示最长连续子序列的左位置
int left1=0;
//right1表示最长连续子序列的右位置
int right1=2;
/*
    maxsum函数
    （1） 求出最大连续子列和的大小
    （2） 返回最大连续子列和的起始位置和终点位置
*/
int maxsum(int left,int right,int& r,int& l)// l 最大连续子列和的起始位置，r 最大连续子列和的终点位置
{
    // 如果left == right r=l=left=right 返回num[left]
    if(left==right)
    {
        l=left;
        r=right;
        return num[left];
    }  
    int mid=(left+right)/2;
    // l1 r1  左子序列的 最大连续子列和的起始位置和终点位置 
    // l2 r2 右子序列的  最大连续子列和的起始位置和终点位置
    int r1=0,r2=mid+1,l1=mid,l2=right;
    // leftsum 左子序列最大子列和
    int leftsum=maxsum(left,mid,r1,l1);
    // rightsum 同理
    int rightsum=maxsum(mid+1,right,r2,l2);
    int midsum=0;
    int temp=0;
    int r3=right,l3=left;
    // 计算midsum
    for(int i=mid;i<=right;i++)
    {
        temp+=num[i];
        if(temp>midsum)
        {
            midsum=temp;
            r3=i;
        }   
    }
    temp=0;
    int midsum1=0;
    for(int i=mid;i>=left;i--)
    {
        temp+=num[i];
        if(temp>midsum1)
        {
            midsum1=temp;
            l3=i;
        }     
    }
    midsum=midsum+midsum1-num[mid];
    // 比较最大值
    if(midsum>=leftsum&&midsum>=rightsum)
    {
        left1=l3;
        right1=r3;
        return midsum;
    }
    else if(leftsum>=midsum&&leftsum>=rightsum)
    {
        left1=l1;
        right1=r1;
        return leftsum;
    }
    else
    {
        left1=l2;
        right1=r2;
        return rightsum;
    }
   
}
int main()
{
    //输入
    int res=maxsum(0,2,right1,left1);
    cout<<"the  subsequence is";
    for(int i=left1;i<=right1;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl<<"the sum is "<<res;
   
    return 0;
}