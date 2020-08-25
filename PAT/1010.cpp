#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>charToint;//记录0-9,a-z字符对应的进制
long long trans(char*s,long long radix){//转换成10进制
    long long result=0;
    for(int i=0;s[i]!='\0';++i)
        result=result*radix+charToint[s[i]];
    return result;
}
long long findRadix(char*n1,char*n2,long long radix){//查找符合要求的进制
    long long right=trans(n1,radix),left=-1,tag=right;//left指示要查找的进制数的下限，right指示要查找的进制数的上限，tag表示n1表示的十进制数
    for(int i=0;n2[i]!='\0';++i)//找到要查找的进制数的下限
        left=max(left,(long long)charToint[n2[i]]+1);
    while(left<right){//二分查找第一个使得n2指向的字符串表示的数大于等于tag的进制
        long long mid=left+(right-left)/2,k=trans(n2,mid);
        if(k<0||k>=tag)//k<0时表示数据已经超出long long存储范围
            right=mid;
        else if(k<tag)
            left=mid+1;
    }
    if(trans(n2,left)!=tag)//如果查找到的进制下两数不相等，返回-1
        left=-1;
    return left;
}
int main(){
    char s1[11],s2[11];
    long long tag,radix;
    scanf("%s %s%lld%lld",s1,s2,&tag,&radix);
    for(int i=0;i<36;++i)//将0-9,a-z字符对应的进制压入charToint的map中，方便进行转换
        charToint.insert({i<10?i+'0':i-10+'a',i});
    radix=tag==1?findRadix(s1,s2,radix):findRadix(s2,s1,radix);//查找符合条件的进制
    if(radix==-1)//没有找到输出Impossible
        printf("Impossible");
    else//否则直接输出
        printf("%lld",radix);
    return 0;
}