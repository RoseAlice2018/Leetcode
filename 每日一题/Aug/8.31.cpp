#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> visit;
    int num;
    void dfs(vector<vector<int>>& rooms,int x)
    {
        visit[x]=true;
        num++;
        for(auto& it :rooms[x])
        {
            if(!visit[it])
                dfs(rooms,it);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        num=0;
        visit.resize(n);
        dfs(rooms,0);
        return num==n;
    }
};