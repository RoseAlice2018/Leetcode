#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
     {
         int maxarea=0;
         int left=0,right=height.size()-1;
         while (left<=right)
         {
            int temp=(right-left)*(height[left],height[right]);//min 
            if(temp>maxarea)
                maxarea=temp;
            if(height[left]<=height[right])
                left++;
            else 
                right--;
         }
         return maxarea;
         
    }
};