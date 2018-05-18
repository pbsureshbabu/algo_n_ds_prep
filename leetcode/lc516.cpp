// Leetcode prob #516 - longest palindromic subsequence

// lessons learned
// 1. 


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int max(int a, int b) {return a>b?a:b;}
    int longestPalindromeSubseq(string s) {
		vector<int> prev(s.length()+1, 0);
		vector<int> cur(s.length()+1, 0);
		string p=s;
		reverse(p.begin(), p.end());
		cout << p << endl;
		for(int i=1; i<=s.length(); i++)
		{
			for(int j=1; j<=s.length(); j++)
				if(s[i-1]==p[j-1])
					cur[j]=prev[j-1]+1;
				else
					cur[j]=max(cur[j-1], prev[j]);
			//for(int k=0; k<cur.size(); k++)
			//	cout << cur[k] << " ";
			//cout << endl;
			prev=cur;
		}
		return prev[s.length()];
    }
};


int main()
{
	Solution sol;
	int res=0;
	string s="hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr";
	//string s="suresh";
	res = sol.longestPalindromeSubseq(s);

	cout << res << endl;
	
	return 0;
}

