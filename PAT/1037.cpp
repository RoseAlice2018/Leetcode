#include<iostream>
#include<algorithm>
using namespace std;
int min(int a,int b)
{
    if(a>b)
        return b;
    else 
        return a;
}
int main()
{
    long long NumCoupons;
    cin>>NumCoupons;
    long long cupons[NumCoupons];
    for(int i=0;i<NumCoupons;i++)
        cin>>cupons[i];
    long long Numproducts;
    cin>>Numproducts;
    long long products[Numproducts];
    for(int i=0;i<Numproducts;i++)
        cin>>products[i];
    double maxreturn=0;
    long long cup=0,pro=0;
    long long midcu=0,midpr=0;
    sort(cupons,cupons+NumCoupons);
    sort(products,products+Numproducts);
    for(int i=0;i<NumCoupons;i++)
        if(cupons[i]>0)
        {
            midcu=i;
            break;
        }
    for(int i=0;i<Numproducts;i++)
        if(products[i]>0)
        {
            midpr=i;
            break;
        }
    for(int i=0;i<min(midpr,midcu);i++)
        maxreturn+=products[i]*cupons[i];
    int right=Numproducts-1;
    for(int i=NumCoupons-1;i>=midcu;i--)
    {
        if(right<midpr)
            break;
        maxreturn+=(products[right]*cupons[i]);
        right--;
    }
    if(maxreturn<0)
        cout<<0;
    else 
        cout<<maxreturn;
    return 0;
}
// while (temp>=0)
    // {
    //     long cup=select_cupons(cupons,NumCoupons,use_coup);
    //     long product=select_products(products,Numproducts,use_products);
    // }
// int select_cupons(int coupons[],int N,int use[])
// {
//     int max=INT32_MIN;
//     int uselocation=0;
//     for(int i=0;i<N;i++)
//     {
//         if(coupons[i]>max&&use[i]==0)
//         {
//             max=coupons[i];
//             uselocation=i;
//         }    
//     }
//     use[uselocation]=1;
//     return max;
// }
// int select_products(int coupons[],int N,int use[])
// {
//     int max=INT32_MIN;
//     int uselocation=0;
//     for(int i=0;i<N;i++)
//     {
//         if(coupons[i]>max&&use[i]==0)
//         {
//             max=coupons[i];
//             uselocation=i;
//         }    
//     }
//     use[uselocation]=1;
//     return max;
// }
    