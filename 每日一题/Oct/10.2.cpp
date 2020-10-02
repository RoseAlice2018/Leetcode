#include<string>
#include<set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> Jewellery;
        for(int i=0;i<J.size();i++)
        {
            Jewellery.insert(J[i]);
        }
        int res=0;
        for(int i=0;i<S.size();i++)
        {
            if(Jewellery.count(S[i]))
                res++;
        }
        return res;
    }
};