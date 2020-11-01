#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) 
    {
        unordered_map<int,vector<int>> dic;
        for(int i=0;i<pieces.size();i++)
            dic.insert(pair<int,vector<int>>(pieces[i][0],pieces[i]));
        int index=0;
        for(;index<arr.size();)
        {
            int first=arr[index];
            if(dic.count(first))
            {
                for(int i=0;i<dic[first].size();i++)
                {
                    
                    if(index<arr.size()&&arr[index]==dic[first][i])
                    {
                        index++;
                    }
                    else
                    {
                        return false;
                    } 
                }
            }
            else
            {
                return false;
            }
            
        }
        return true;
    }
};