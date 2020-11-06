#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        map<int,vector<int>> dic;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            int count=0;//count the number of '1'
            int temp=arr[i];
            while(temp>0)
            {
                if((temp&1)==1)
                {
                    count++;
                }
                temp>>=1;
            }
            if(dic.count(count))
            {
                dic[count].push_back(arr[i]);
            }
            else
            {
                vector<int> t;t.push_back(arr[i]);
                dic.insert(pair<int,vector<int>>(count,t));
            }
        }
        map<int,vector<int>>::iterator it=dic.begin();
        vector<int> res;
        for(;it!=dic.end();it++)
        {
            res.insert(res.end(),(*it).second.begin(),(*it).second.end());
        }
        return res;
    }
};