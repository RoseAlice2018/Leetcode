#include<iostream>
#include<unordered_map>
using namespace std;
struct poly
{
    double coeff;
    int exp;
};
poly multiply(poly a,poly b)
{
    int exp=a.exp+b.exp;
    double coe=a.coeff*b.coeff;
    poly res;
    res.exp=exp;
    res.coeff=coe;
    return res;
}
int main()
{
    int N1,N2;
    cin>>N1;
    poly first[N1+2];
    for(int i=0;i<N1;i++)
            scanf("%d %lf",&first[i].exp,&first[i].coeff);
    cin>>N2;
    poly second[N2+2];
    for(int i=0;i<N2;i++)
        scanf("%d %lf",&second[i].exp,&second[i].coeff);
    unordered_map<int,double> res;
    for(int i=0;i<N1;i++)
    {
        for(int j=0;j<N2;j++)
        {
            poly N3=multiply(first[i],second[j]);
            res[N3.exp]+=N3.coeff;
        }
    }
    unordered_map<int,double>::iterator it;
    printf("%d",res.size());
    for(it=res.begin();it!=res.end();it++)
    {
        printf(" %d %.1f",it->first,it->second);
    }

    return 0;
}