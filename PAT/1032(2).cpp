#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{
    char data[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
    int Next[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
    int begin1,begin2,N;//链表1起始地址、链表2起始地址，给出的结点总数
    unordered_set<int> list1,list2;//存储2个链表所有结点地址的vector
    scanf("%d%d%d",&begin1,&begin2,&N);
    while(N--)
    {
        int a;
        scanf("%d",&a);
        scanf(" %c %d",&data[a],&Next[a]);
    }
    while(begin1!=-1)
    {//存储链表1的所有结点地址
        list1.insert(begin1);
        begin1=Next[begin1];
    }
    while(begin2!=-1)
    {//存储链表2的所有结点地址
        if(list1.count(begin2))
        {
            cout<<begin2;
            return 0;
        }
        begin2=Next[begin2];
    }
   
    printf("-1");//如果没查找到输出-1
    return 0;
}