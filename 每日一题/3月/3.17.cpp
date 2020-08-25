#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int len=0;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            int num[26]={0};
            int tag=0;
            for(int k=0;k<chars.size();k++)
            {
                int c=chars[k]-'a';
                num[c]++;
            }
            for(int j=0;j<temp.size();j++)
            {
                int t=temp[j]-'a';
                if(num[t]>0)
                    num[t]--;
                else
                {
                    tag=1;
                    break;
                }          
            }
            if(tag==0)
                len+=temp.size();            
        }
        return len;
    }
};