#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> dic;
        int maxx=0;
        for(int i=0;i<rectangles.size();i++)
        {
            int maxlen=min(rectangles[i][0],rectangles[i][1]);
            if(dic.count(maxlen))
                dic[maxlen]++;
            else 
                dic[maxlen]=1;
            if(maxlen>maxx)
                maxx=maxlen;
        }
        return dic[maxx];
    }
};