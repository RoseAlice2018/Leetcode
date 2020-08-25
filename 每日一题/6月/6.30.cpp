#include<stack>
#include<iostream>
using namespace std;
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() 
    {

    }
    
    void appendTail(int value) 
    {
        s1.push(value);
    }
    
    int deleteHead()
     {
         if(!s2.empty())
         {
             int t=s2.top();
             s2.pop();
            return t;
         }
         else
         {
             while(!s1.empty())
             {
                 int t=s1.top();
                 s1.pop();
                 s2.push(t);
             }
             if(s2.empty())
                return -1;
             int t=s2.top();
             s2.pop();
             return t;
         }
         
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */