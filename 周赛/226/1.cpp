#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    unordered_map<int,int> dic;
    void insert_map(int key)
    {
        int temp=0;
        while(key>0)
        {
            int t = key%10;
            temp += t;
            key = (key-t)/10;
        }
        if(dic.count(temp))
            dic[temp]++;
        else
        {
            dic[temp]=1;
        }
    }
    int countBalls(int lowLimit, int highLimit) {
        for(int i=lowLimit;i<=highLimit;i++)
        {
            insert_map(i);
        }
        int max=0;
        for(auto iter = dic.begin();iter != dic.end();iter++)
        {
            if(iter->second>max)
                max=iter->second;
        }
        return max;
    }
};