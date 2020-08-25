#include<iostream>
#include<algorithm>
using namespace std;
struct  price_per
{
    double num=0;
    double per_price=0;
    double total_money=0;
};
bool cmp(price_per a,price_per b)
{
    return a.per_price>b.per_price;
}
int main()
{
    int N;// kinds of mooncakes
    double Total_;// total_need
    scanf("%d %lf",&N,&Total_);
    double cakes[N+2];
    double price[N+2];
    for(int i=1;i<=N;i++)
        scanf("%lf",&cakes[i]);
    for(int i=1;i<=N;i++)
        scanf("%lf",&price[i]);
    price_per mooncakes[N+2];
    for(int i=0;i<N;i++)
    {
        mooncakes[i].per_price=price[i+1]/cakes[i+1];
        mooncakes[i].num=cakes[i+1];
        mooncakes[i].total_money=price[i+1];
    }
    double profit=0;
    sort(mooncakes,mooncakes+N,cmp);
    for(int i=0;i<N;i++)
    {
        if(Total_-mooncakes[i].num>=0)
        {
            profit+=mooncakes[i].total_money;
            Total_-=mooncakes[i].num;
        }
        else 
        {
            profit+=Total_*mooncakes[i].per_price;
            Total_=0;
            printf("%.2lf",profit);
            break;
        }
    }
    
    return 0;
}