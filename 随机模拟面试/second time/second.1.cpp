  #include<iostream>
  #include<vector>
  using namespace std;
  class CustomFunction {
  public:
      // Returns f(x, y) for any given positive integers x and y.
      // Note that f(x, y) is increasing with respect to both x and y.
      // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
      int f(int x, int y);
  };
 

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {
        vector<vector<int>> res;
        for(int i=0;i<z;i++)
        {
            for(int j=0;j<z;j++)
            {
                vector<int> temp;
                if(customfunction.f(i,j)==z)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
                temp.clear();
            }
        }
        return res;

    }
};