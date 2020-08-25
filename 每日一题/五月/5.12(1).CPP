#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> Minstack;
    stack<int> mint;
    MinStack() 
    {
        mint.push(INT32_MAX);
    }
    
    void push(int x)
     {
        Minstack.push(x);
        mint.push(min(mint.top(),x));
    }
    
    void pop() 
    {
         Minstack.pop();
         mint.pop();
    }
    
    int top()
     {
       return Minstack.top();
    }
    
    int getMin()
     {
        return mint.top();
    }

};