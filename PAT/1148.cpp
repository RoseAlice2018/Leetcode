#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int a=0,b=0;// res;
    int statement[120];
    for(int i=1;i<=N;i++)
    {
        int temp;
        scanf("%d",&temp);   
        statement[i]=temp;             
    }
    int panel[120]={1};// positive means human while negative means werewolves
    for(int i=0;i<120;i++)
    {
    	panel[i]=1;
	}
    for(int i=1;i<=N;i++)
    {
        panel[i]=-1;
        for(int j=i+1;j<=N;j++)
        {
            panel[j]=-1;
            int c=0;
            // 1 assume that i is the lier
            if(statement[i]*panel[abs(statement[i])]<0)
                c=i;
            // 2 assume that j is the lier
            if(statement[j]*panel[abs(statement[j])]<0)
            {
                if(c>0)
                    c=-1;// this is impossible
                else
                    c=j;                
            }
            int count=0;//count the liar of human
            if(c>0)// 
            {
                for(int k=1;k<=N;k++)
                {
                    if(k!=j&&k!=i&&(statement[k]*panel[abs(statement[k])]<0))
                        count++;
                }
            }
            if(count==1&&c>0)
            {
                a=i;
                b=j; 
                cout<<a<<" "<<b;
                return 0;
            }
            // recover
            panel[j]=1;
//            cout<<j<<" "<<panel[j]<<endl;
                
        }
        panel[i]=1;
    }
    cout<<"No Solution";
    return 0;
}