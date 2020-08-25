#include<iostream>
using namespace std;
int maxx(double Panel[3][3],int line)
{
    int max=0;
    int res=0;
    for(int i=0;i<3;i++)
    {
        if(Panel[line][i]>max)
        {
            max=Panel[line][i];
            res=i;
        }
    }
    return res;
}
int main()
{
    double Panel[3][3];
    char Game[3]={'W','T','L'};
    char res[3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cin>>Panel[i][j];
    }
    double betrate=1;
    for(int i=0;i<3;i++)
    {
        int temp=maxx(Panel,i);
        betrate*=Panel[i][temp];
        res[i]=Game[temp];
    }
    double profit=(betrate*0.65-1.0)*2;
    for(int i=0;i<3;i++)
        cout<<res[i]<<" ";
    printf("%.2f",profit);
    return 0;
}