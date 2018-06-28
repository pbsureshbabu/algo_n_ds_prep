#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;

        int output=0;
        int input=x;
        while(x)
        {
            output*=10;
            output+=(x%10);
            x/=10;
        }
        if(input==output)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    bool result;
    int input=10;

    result=sol.isPalindrome(input);
    cout << result << endl;

    return 0;
}