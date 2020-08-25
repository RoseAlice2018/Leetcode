#include<vector>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    struct point
    {
        int x=0;
        int y=0;
        int size=y-x+1;
    };
    int findLatestStep(vector<int>& arr, int m) {
        vector<int> str(arr.size()+10,0);
        vector<point*> table;
        int res=-1;// the result
        for(int i=0;i<arr.size();i++)
        {
            // the i step;
            str[arr[i]]=1;
            // change the table;
            point* t=new point();
            int tag=0;
            if(str[arr[i]-1]==1)// merge
            {
                tag=2;
                for(point* p:table)
                {
                    if(p->y==arr[i]-1)
                    {
                        //get it;
                        t->x=p->x;
                        p->x=0;
                        p->y=0;
                        break;
                    }
                }
            }
            if(str[arr[i]+1]==1)//merge
            {
                if(tag)
                    tag=3;
                else 
                    tag=4;
                for(point* p:table)
                {
                    if(p->x==arr[i]+1)
                    {
                        t->y=p->y;
                        p->x=0;
                        p->y=0;
                        break;
                    }
                }
            }
            if(tag)
            {
                if(tag==2)
                {
                    t->y=arr[i];
                }
                else if(tag==4)
                {
                    t->x=arr[i];
                }
                 table.push_back(t);
            }
            else
            {
                t->x=arr[i];
                t->y=arr[i];
                table.push_back(t);
            }
            for(point* p:table)
            {
                if(p->size==m)
                {
                    res=i+1;
                }
            }
        }
        return res;
    }
};