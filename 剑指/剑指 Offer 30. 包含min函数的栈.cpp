#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> realstack;
    stack<int> minstack;
    MinStack() {
        ;
    }
    
    void push(int x) {
        realstack.push(x);
        if(minstack.empty())
        {
            minstack.push(x);
        }
        else{
            if(x<=minstack.top())
            {
                minstack.push(x);
            }
            else{
                minstack.push(minstack.top());
            }
        }
    }
    
    void pop() {
        realstack.pop();
        minstack.pop();        
    }
    
    int top() {
        return realstack.top();
    }
    
    int min() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */