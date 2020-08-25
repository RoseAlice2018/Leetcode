class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
      int n = satisfaction.size();
      sort(satisfaction.begin(),satisfaction.end());
      int ans = 0,sum = 0,all = 0;
      for(int i = n - 1; i >= 0 ; i--)
      {
        all += sum + satisfaction[i];
        ans = max(ans,all);
        sum += satisfaction[i];
      }
      return ans;
    }
};