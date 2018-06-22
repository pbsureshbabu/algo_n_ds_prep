#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int rev_value=0;
        int cnt=0;
        int base=1;
        int sign=1;
        if(x<0)
            sign=-1;
        while(x && cnt<9)
        {
            rev_value*=10;
            rev_value+=(x%10);
            x/=10;
            cnt++;
        }
        if(x)
        {
            if(abs(rev_value)>INT_MAX/10)
            {
                return 0;
            }
            if(abs(rev_value)==INT_MAX/10 && x>7)
            {
                if(sign==1 || (sign==-1 && x>8))
                    return 0;
                else
                    return INT_MIN;
            }
            return (rev_value*10+x);
        }
        else
            return rev_value;
    }
};

int main()
{
    Solution sol;
    int input=2147483647;
    int result;

    result=sol.reverse(input);
    cout << result << endl;
 
    return 0;
}