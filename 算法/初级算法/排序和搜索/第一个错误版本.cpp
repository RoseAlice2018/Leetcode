// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version)
{

}
class Solution {
public:
    int binarysearch(int left,int right)
    {
        int mid=(right-left)/2+left;
        if(left==right)
            return left;
        if(isBadVersion(mid)==false)
        {
            return binarysearch(mid+1,right);
        }
        else
        {
            return binarysearch(left,mid);
        }
        
        
    }
    int firstBadVersion(int n) 
    {
       return binarysearch(1,n);
    }
};