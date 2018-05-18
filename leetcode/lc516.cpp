// Leetcode prob #516 - longest palindromic subsequence

// lessons learned
// 1. 


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	int lut[1000][1000];
public:
	int max(int a, int b) {return a>b?a:b;}
	int L( string s, int lut[1000][1000], int i, int  j )
	{
		if(i>j) 
			return 0;
		if(lut[i][j]!=-1) 
			return lut[i][j];
		if(i==j) 
			{ lut[i][j]=1; return lut[i][j];}
		if(s[i]==s[j]) 
			{ lut[i][j]=2+L(s, lut, i+1, j-1); return lut[i][j];}
		else 
			{ lut[i][j]=max(L(s, lut, i+1, j), L(s, lut, i, j-1)); return lut[i][j];}
	}
	
    int longestPalindromeSubseq(string s) {
		//vector<vector<int> > lut(s.size(), vector<int> (s.size()));
		if(s.size()==0)
			return 0;

		for(int i=0; i<s.size(); i++)
			for(int j=0; j<s.size(); j++)
				lut[i][j]=-1;
        return L(s, lut, 0, s.size()-1);
    }
};


int main()
{
	Solution sol;
	int res=0;
	string s="hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr";

	res = sol.longestPalindromeSubseq(s);

	cout << res << endl;
	
	return 0;
}

