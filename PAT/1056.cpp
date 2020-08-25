#include<iostream>
#include<queue>
using namespace std;
struct  mice
{
    /* data */
    int rank;
    int weight;
};
int main()
{
    int Np,Ng;
    cin>>Np>>Ng;
    mice miceweight[Np];
    queue<mice> contest;
    for(int i=0;i<Np;i++)
    {
        cin>>miceweight[i].weight;
    }
    for(int i=0;i<Np;i++)
    {
        int temp;
        cin>>temp;
        contest.push(miceweight[temp]);       
    }
    mice res[Np];
    int count=0;
    while (contest.size()>1)
    {
        int group=contest.size()/Ng;
        int del=contest.size()%Ng;
        int tag=0;
        if(del>0)
        {
            group++;
            tag=1;
        }
            
        mice tempp[Ng];
        int maxweightt=0;
        int winnerr;
        for(int i=0;i<del;i++)
        {
            
            //记录每组数据
           
            tempp[i]=contest.front();
            if(tempp[i].weight>maxweightt)
                {
                    maxweightt=tempp[i].weight;
                    winnerr=i;
                }
             contest.pop();             
            
            //胜者继续比赛
            
        }
        contest.push(tempp[winnerr]);
            //败者进行标记
            for(int j=0;j<del;j++)
            {
                if(j!=winnerr)
                {
                    res[count].weight=tempp[j].weight;
                    res[count].rank=group+1;
                    count++;
                }
            }
        for(int i=0;i<group-tag;i++)
        {
            mice temp[Ng];
            int maxweight=0;
            int winner;
            //记录每组数据
            for(int j=0;j<Ng;j++)
            {
                temp[j]=contest.front();
                if(temp[j].weight>maxweight)
                {
                    maxweight=temp[j].weight;
                    winner=j;
                }
                contest.pop();             
            }
            //胜者继续比赛
            contest.push(temp[winner]);
            //败者进行标记
            for(int j=0;j<Ng;i++)
            {
                if(j!=winner)
                {
                    res[count].weight=temp[j].weight;
                    res[count].rank=group+1;
                    count++;
                }
            }
        }
        //不够Ng的分为一组
        
    }
    //最后1组
    res[count].weight=contest.front().weight;
    res[count++].rank=1;
    for(int i=0;i<count;i++)
    {
        cout<<res[i].rank<<" "<<res[i].weight<<endl;
    }
    
    
    return 0;
}
