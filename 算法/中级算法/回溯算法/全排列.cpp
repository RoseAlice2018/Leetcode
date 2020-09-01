class Solution {
public:
    vector<vector<int>> res;
    bool contain(vector<int>&nums,int a)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a)
                return true;
        }
        return false;
    }
    void trace(vector<int>& nums,vector<int>& temp)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(contain(temp,nums[i]))
                continue;
            temp.push_back(nums[i]);
            trace(nums,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        trace(nums,temp);
        return res;
    }
};