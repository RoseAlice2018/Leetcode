#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(denominator==0) return "";
        if(numerator==0)    return "0";
        long long num=static_cast<long long>(numerator);
        long long denom=static_cast<long long>(denominator);
        if((num>0)^(denom>0))res.push_back('-');
        num=llabs(num);denom=llabs(denom);
        res.append(to_string(num/denom));
        num%=denom;
        if(num==0) return res;
        res.push_back('.');
        int index=res.size()-1;
        unordered_map<int,int> record;
        while(num&&record.count(num)==0){
            record[num]=++index;
            num*=10;
            res+=to_string(num/denom);
            num%=denom;
        }
        if(record.count(num)==1){
            res.insert(record[num],"(");
            res.push_back(')');
        }
        
        return res;
    }
};