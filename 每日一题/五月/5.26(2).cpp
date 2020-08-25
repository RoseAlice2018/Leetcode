#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r)
         {
            int mid = (l + r) >> 1;//先选择mid看是否为target
            int cnt = 0;
            int equal=0;
            for (int i = 0; i < n; ++i) 
            {
                cnt +=(nums[i] <= mid);//计算cnt[mid];
                if(nums[i]==mid)
                    equal++;
            }
            int cntj=n-cnt+equal;// cnt[]
            if (cnt <= mid) //cnt[mid]<=mid,显然target>mid,缩小区间
            {
                l = mid + 1;
            } 
            else 
             {
                r=mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};