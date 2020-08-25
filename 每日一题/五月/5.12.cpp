#include<iostream>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        
    }
    
    void push(int x)
     {
        size[cur]=x;
        cur++;
    }
    
    void pop() 
    {
         min=INT32_MAX;
        cur--;
    }
    
    int top()
     {
        return size[cur-1];
    }
    
    int getMin()
     {
        for(int i=0;i<cur;i++)
        {
            if(size[i]<min)
                min=size[i];
        }
        return min;
    }
private:
    int size[10000];
    int cur=0;
    int min=INT32_MAX;
};