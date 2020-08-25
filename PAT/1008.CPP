#include<iostream>
#include<vector>
using namespace std;
int totaltime=0;
void gotoo(int now,int next)
{
    //up
    if(now<=next)
    {
        totaltime+=(next-now)*6+5;
    }
    else if(now>next)
    {
        //down
        totaltime+=(now-next)*4+5;
    }
    return;
}
int main()
{
    int N;
    cin>>N;
    vector<int> floor;
    floor.push_back(0);
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        floor.push_back(temp);
    }
    for(int i=0;i<floor.size()-1;i++)
    {
        gotoo(floor[i],floor[i+1]);
    }
    cout<<totaltime;
    return 0;
}