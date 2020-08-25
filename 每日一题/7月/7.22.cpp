#include<vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers)
     {
         int res;
         if(numbers.size()==0)
            return 0;
        else if(numbers.size()==1)
            return numbers[0];
        int head=0,end=numbers.size()-1;
        if(numbers[head]<numbers[end])
        {
            return numbers[head];
        }
        else
        {
            while(end-1>=0&&numbers[end-1]<=numbers[end])
                end--;
            res=numbers[end];
        }
        return res;
    }
};