#include<iostream>
#include<string>
using namespace std;
class Solution
 {
public:
    bool validPalindrome(string s) 
    {
        int left=0,right=s.size()-1;
        int tag=0;
        int temp1=0,temp2=0;
        while (left<=right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else if(tag==0)
            {
                //记录此时状态
                temp1=left;
                temp2=right;
                //跳过此时异常点
                right--;
                tag++;
            }
            else if(tag==1)
            {
                left=temp1;
                right=temp2;
                //恢复现场
                left++;
                tag++;
            }
            else if(tag==2)
            {
                return false;
            }
        }
        return true;
    }
};