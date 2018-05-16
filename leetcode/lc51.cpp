// #51 - N queens problem
//
// lessons learned

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
private:
	vector<vector<string> > res;
    vector<vector<int> > qsol;
public:
	bool queenhelper( vector<int> &rcinfo, int r )
	{
		if(r==rcinfo.size()) 
		{
			qsol.resize(qsol.size()+1, vector<int>(rcinfo.size()));
			for(int r=0; r<rcinfo.size(); r++)
			{
				qsol[qsol.size()-1][r]=rcinfo[r];
			}
			return true;
		}

		for(int c=0; c<rcinfo.size(); c++)
		{
			bool ua=false;
			for(int i=0; i<r; i++)
			{
				if(c==rcinfo[i]) ua=true;
				if(abs(i-r)==abs(c-rcinfo[i])) ua=true;
			}
			if(!ua)
			{
				rcinfo[r]=c;
				queenhelper( rcinfo, r+1 );
			}
			rcinfo[r]=-1;
		}
		return false;
	}
	vector<vector<string> > solveNQueens(int n)
	{
		vector<int> rcinfo(n);
		for(int r=0; r<n; r++)
			rcinfo[r]=-1;

		for(int c=0; c<n; c++)
		{
			rcinfo[0]=c;
			queenhelper( rcinfo, 1 );
			rcinfo[0]=-1;
		}
		convertrc(qsol);
		return res;
		
	}
	vector<vector<string> > convertrc( vector<vector<int> > &rcinfo )
	{
		if( rcinfo.size()==0 ) return res;
		else { res.resize(rcinfo.size(), vector<string>(rcinfo[0].size())); }

		for(int sol=0; sol<rcinfo.size(); sol++)
		{
			for(int r=0; r<rcinfo[sol].size(); r++)
			{
				for(int c=0; c<rcinfo[sol].size(); c++)
					if(rcinfo[sol][r]==c) res[sol][r]=res[sol][r]+'Q';
					else res[sol][r]=res[sol][r]+'.';
			}
		}
		return res;
	}
};

int main()
{
	int n=5;
	Solution sol;
	vector<vector<string> > res;

	res = sol.solveNQueens( n );

	for(int so=0; so<res.size(); so++ )
	{
		for(int r=0; r<res[so].size(); r++)
			cout << res[so][r] << endl;
		cout << endl;
	}
	
	return 0;
}


