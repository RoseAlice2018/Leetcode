#include<string>
using namespace std;
class Solution {
public:
    int check(int num[128])
    {
        int max=0;
        for(int i=0;i<128;i++)
        {
            if(num[i]>1)
                return false;
            else if(num[i]==1)
                max++;
        }
        return max;
    }
    int lengthOfLongestSubstring(string s) 
    {
        int numofchar[128]={0};
        int left=0,right=0;
        int maxsize=0;
        for(;right<s.size(); right++)
        {
            //字符串右移动
            numofchar[s[right]]++;
            int max=check(numofchar);
            if(max)//可以右移动
            {
                if(max>maxsize)
                    maxsize=max;
            }
            else
            {
                //去掉字符串左
                if(left<=right)
                 {
                    numofchar[s[left]]--;
                     left++;
                 }
            }
            
        }
        return maxsize;
    }
};