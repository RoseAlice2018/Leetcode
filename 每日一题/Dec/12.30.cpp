#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> heap;
      for(auto i:stones)
        heap.push(i);
      while (heap.size()>1)
      {
          int p=heap.top();
          heap.pop();
          int q=heap.top();
          heap.pop();
          if(p==q)
            ;
          else
          {
              heap.push(p-q);
          }
      }
      return heap.empty()?0:heap.top();       
    }
};