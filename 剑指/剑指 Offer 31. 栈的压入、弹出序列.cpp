#include<vector>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> dic;
        int i=0;
        int index=0;
        while(i<pushed.size())
        {
            dic.push(pushed[i]);
            while(!dic.empty()&&dic.top()==popped[index])
            {
                dic.pop();
                index++;
            }
            i++;
        }
        return dic.empty()?true:false;
    }
};