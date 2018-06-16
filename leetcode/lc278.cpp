// very valuable lesson learned
// never do (l+r)/2; it can overflow.
// it would be better to do l+(r-l)/2;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        int result = r;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(isBadVersion(m))
            {
                result=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return result;    
    }
};

