#include<bits/stdc++.h>  
using namespace std;  
double A[1005],result[2005];  
int main(){  
    int K,a,size=0;
    double b;
    scanf("%d",&K);  
    while(K--){  //读取第一个多项式存储到A数组中  
        scanf("%d%lf",&a,&b);  
        A[a]=b;  
    }  
    scanf("%d",&K);  
    while(K--){  //读取第二个多项式  
        scanf("%d%lf",&a,&b);  
        for(int i=0;i<1005;++i)  
            result[a+i]+=A[i]*b;//将相乘结果报错到result中  
    }  
    for(int i=0;i<2005;++i) //统计系数不为0的项数  
        if(result[i]!=0.0)  
            ++size;  
    printf("%d",size);  
    for(int i=2005;i>=0;--i)  //输出每一项  
        if(result[i]!=0.0)  
            printf(" %d %.1f",i,result[i]);  
    return 0;  
}  