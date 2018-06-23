#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        int cnt_arr[256];
        for(unsigned int i=0; i<256; i++)
            cnt_arr[i]=0;
        int g_max=0;
        int s=0;
        int i=0;

        while(i<str.length())
        {
            cnt_arr[str[i]]++;
            if(cnt_arr[str[i]]>1)
            {
                while(s<i)
                {
                    cnt_arr[str[s]]--;
                    if(cnt_arr[str[s++]]==1)
                        break;
                }
            }
            else
                g_max=max(g_max, i-s+1);
            i++;
        }
        return g_max;        
    }
};

int main()
{
    Solution sol;
    string str="pwwkew";
    int result=0;

    result = sol.lengthOfLongestSubstring(str);
    cout << result << endl;

    return 0;
}