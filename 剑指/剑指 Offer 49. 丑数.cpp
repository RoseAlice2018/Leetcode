#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
   int nthUglyNumber(int n) {
        if(!n)return 0;
        vector<int>ugly(n,0);
        ugly[0] = 1;     //基础丑数为1
        int i=0,j=0,k=0;  //初始分别指向三个有序链表第一个元素,这三个有序链表是想象出来的，分别就是ugly数组元素分别乘以2,3,5得到的
        for(int idx=1;idx<n;idx++)
        {
            int tmp =  min(ugly[i]*2,min(ugly[j]*3,ugly[k]*5));    
            //三个链表可能有相同元素，所以只要是最小的，都要移动指针
            if(tmp == ugly[i]*2)i++;
            if(tmp == ugly[j]*3)j++;
            if(tmp == ugly[k]*5)k++;
            ugly[idx] = tmp;
        }
        return ugly[n-1];
    }
};