#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        if(adjacentPairs.size()==0)
            return res;
        unordered_map<int,int> dic;
        unordered_map<int,vector<int>> map_pairs;
        for(int i=0;i<adjacentPairs.size();i++)
        {
            int first =adjacentPairs[i][0];
            int second = adjacentPairs[i][1];
            if(dic.count(adjacentPairs[i][0]))
                dic[adjacentPairs[i][0]]++;
            else 
                dic[adjacentPairs[i][0]]=1;
            if(dic.count(adjacentPairs[i][1]))
                dic[adjacentPairs[i][1]]++;
            else 
                dic[adjacentPairs[i][1]]=1; 
            map_pairs[first].push_back(second);
            map_pairs[second].push_back(first);         
        }
        int begin = 0;
        for(auto iter=dic.begin();iter!=dic.end();iter++)
        {
            if(iter->second==1)
            {
                begin =  iter->first;
                break;
            }
        }
        res.push_back(begin);
        int temp=begin;
        while(1){
            for(int i=0;i<map_pairs[begin].size();i++)
            {
                std::cout<<map_pairs[begin][i]<<" ";
                if(map_pairs[begin][i]!=temp)
                {
                    //
                    temp = begin;
                    begin = map_pairs[begin][i];
                    res.push_back(begin);
                }
            }
            cout<<endl;
            if(res.size()==adjacentPairs.size()+1)
                    break;
        }
        return res;
    }
};