#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    char data[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
    int Next[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
    int begin1,begin2,N;//链表1起始地址、链表2起始地址，给出的结点总数
    vector<int> list1,list2;//存储2个链表所有结点地址的vector
    scanf("%d%d%d",&begin1,&begin2,&N);
    while(N--)
    {
        int a;
        scanf("%d",&a);
        scanf(" %c %d",&data[a],&Next[a]);
    }
    while(begin1!=-1)
    {//存储链表1的所有结点地址
        list1.push_back(begin1);
        begin1=Next[begin1];
    }
    while(begin2!=-1)
    {//存储链表2的所有结点地址
        list2.push_back(begin2);
        begin2=Next[begin2];
    }
    for(int i=0;i<list1.size();++i)//暴力查找两个链表中相同结点的起始地址
        for(int j=0;j<list2.size();++j)
            if(list1[i]==list2[j]){//查找到
                printf("%05d",list1[i]);//直接输出，注意输出不够5位数字的要在高位补0
                return 0;//直接返回不再执行其他语句
            }
    printf("-1");//如果没查找到输出-1
    return 0;
}