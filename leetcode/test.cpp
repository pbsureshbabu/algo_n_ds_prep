#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class convert
{
private:
	vector<vector<string> > res;
public:
	bool queenhelper( vector<int> &rcinfo, int r )
	{
		if(r==rcinfo.size()) return true;

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
				bool val;
				val=queenhelper( rcinfo, r+1 );
				if(val==true) return true;
				else rcinfo[r]=-1;
			}
		}
		return false;
	}
	vector<vector<string> > solveQueen(int n)
	{
		vector<vector<int> > qsol;
		vector<int> rcinfo(n);
		for(int r=0; r<n; r++)
			rcinfo[r]=-1;

		for(int c=0; c<n; c++)
		{
			bool retval;
			rcinfo[0]=c;
			retval = queenhelper( rcinfo, 1 ); // always start from row 0
			if(retval==true)
			{
				// handle the solution
				qsol.resize(qsol.size()+1, vector<int>(n));
				for(int r=0; r<n; r++)
				{
					qsol[qsol.size()-1][r]=rcinfo[r];
					rcinfo[r]=-1;
				}
			}
			else
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
	convert con;
	vector<vector<string> > res;

	res = con.solveQueen( n );

	for(int sol=0; sol<res.size(); sol++ )
	{
		for(int r=0; r<res[sol].size(); r++)
			cout << res[sol][r] << endl;
		cout << endl;
	}
	
	return 0;
}
