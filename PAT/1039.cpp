#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    unordered_map<string,vector<int>> res;
    int N,K;
    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++)
    {
        int id,k;
        scanf("%d%d",&id,&k);
        for(int i=0;i<k;i++)
        {
            string name;
            cin>>name; 
            if(res.count(name))
            {
                res[name].push_back(id);
            }
            else
            {
                vector<int> temp;
                temp.push_back(id);
                res.insert(pair<string,vector<int>>(name,temp));
            }  
        }
    }
    for(int i=0;i<N;i++)
    {
        string checkName;
        cin>>checkName;
        vector<int> temp=res[checkName];
        sort(temp.begin(),temp.end());
        cout<<checkName<<" ";
        printf("%d",temp.size());
        for(int j=0;j<temp.size();j++)
        {
            printf(" %d",temp[j]);
        }  
        if(i<N-1)
        {
            printf("\n");
        }     
        
    }
     
    return 0;
}