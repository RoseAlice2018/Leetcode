#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    unordered_set<int> resp;
    for(int i=1;i<=n;i++)
        resp.insert(i);
    while(m--)
    {
        int temp;
        cin>>temp;
        for(int i=temp;i<=n;i+=temp)
            resp.erase(i);
    }
    cout<<resp.size();
    return 0;
}