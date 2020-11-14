#include<vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int num[1001]={0};
        vector<int> res;
        for(int i=0;i<arr1.size();i++)
        {
            num[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++)
        {
            int temp=arr2[i];
            int count=num[temp];
            while(count--)
            {
                res.push_back(temp);
            }
            num[temp]=0;
        }
        for(int i=0;i<1001;i++)
        {
            if(num[i]!=0)
            {
                while(num[i]--)
                {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};