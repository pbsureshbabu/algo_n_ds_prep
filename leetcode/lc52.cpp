#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
private:
    int total_sol;
public:
	bool queenhelper( vector<int> &rcinfo, int r )
	{
		if(r==rcinfo.size()) 
		{
			total_sol++;
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
	int totalNQueens( int n )
	{
		total_sol=0;
		vector<int> rcinfo(n);
		for(int r=0; r<n; r++)
			rcinfo[r]=-1;

		for(int c=0; c<n; c++)
		{
			rcinfo[0]=c;
			queenhelper( rcinfo, 1 );
			rcinfo[0]=-1;
		}
		return total_sol;
	}
};


int main()
{
	int n=5;
	Solution sol;
	int res;
	
	res=sol.totalNQueens(n);
	cout << res << endl;
	
	return 0;
}
