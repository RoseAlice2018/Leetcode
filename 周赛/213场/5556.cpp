#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
     {

         int largestindex=0;
         int returnbricks=0;
         int leavebricks=0;
         int res=climbwithoutladders(heights,bricks,largestindex,0,returnbricks,leavebricks);
         if(ladders==0)
         {
             return res;
         }
        while(ladders--)
        {
            int temp=res+1;
            res=climbwithoutladders(heights,returnbricks,largestindex,largestindex+1,returnbricks,leavebricks);
            if(res==heights.size()-1)
                return res;
            if(res<temp&&temp<=heights.size()-1)
            {
                res=climbwithoutladders(heights,leavebricks,largestindex,res+1,returnbricks,leavebricks);
            }
        }
        
        return res;
    }
    int climbwithoutladders(vector<int>& heights,int bricks,int& largestindex,int beginindex,int& returnbricks,int& leavebricks)
    {
        int index=beginindex;
        int max=0;
        for(;index<heights.size();index++)
        {
            if(index==heights.size()-1||heights[index]>=heights[index+1])
                ;
            else
            {
                if(bricks>=(heights[index+1]-heights[index]))
                {
                    //第一步 更新最大的砖块数量
                    if(heights[index+1]-heights[index]>max)
                    {
                        max=heights[index+1]-heights[index];
                        largestindex=index;
                        returnbricks=bricks;
                    }
                    //更新砖块数量
                    bricks-=(heights[index+1]-heights[index]);
                }
                else
                {
                    leavebricks=bricks;
                    return index;
                }
                
            }
            
        }
        leavebricks=bricks;
        return index-1;
    }
};