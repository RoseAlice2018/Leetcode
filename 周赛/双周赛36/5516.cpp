#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        vector<string> res;
        unordered_map<string,vector<string>> dic;
        for(int i=0;i<keyName.size();i++)
        {
            if(dic.count(keyName[i]))
            {
                // have count it
                dic[keyName[i]].push_back(keyTime[i]);
            }
            else{
                //first try
                vector<string> temp;
                temp.push_back(keyTime[i]);
                dic.insert(pair<string,vector<string>>(keyName[i],temp));
            }
        }
        unordered_map<string,vector<string>>::iterator it=dic.begin();
        for(it=dic.begin();it!=dic.end();it++)
        {
            //res.push_back(to_string(it->second.size()));
            if(it->second.size()<3)
                ;
            else
            {
                int count=0;
                //   res.push_back("did it");
               sort(it->second.begin(),it->second.end());
                for(int i=0;i+2<it->second.size();i++)
                {
                    if(check(it->second[i],it->second[i+1],res))
                    {
                        if(check(it->second[i],it->second[i+2],res))
                        {
                            res.push_back(it->first);
                            count=1;
                            break;
                        }
                        if(count)
                            break;
                    }
                    if(count)
                        break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    
    bool check(string a1,string a2,vector<string>& res)
    {
        int a1_h,a1_m,a2_h,a2_m;
        a1_h=(a1[0]-'0')*10+(a1[1]-'0');
        a2_h=(a2[0]-'0')*10+(a2[1]-'0');
        a1_m=(a1[3]-'0')*10+(a1[4]-'0');
        a2_m=(a2[3]-'0')*10+(a2[4]-'0');
       // cout<<a1_h<<" "<<a1_m<<endl;
        //cout<<a2_h<<" "<<a2_m<<endl;
      
        //  res.push_back(to_string(a1_h));
        // res.push_back(to_string(a1_m));
        // res.push_back(to_string(a2_h));
        // res.push_back(to_string(a2_m));
        if(a2_h<a1_h)
            return false;
        if(a2_h-a1_h>1)
            return false;
        if(a2_h-a1_h<1)
            return true;
        else
        {
            if(a2_m-a1_m<=0)
                return true;
            else 
                return false;
        }
        return false;        
    }
};