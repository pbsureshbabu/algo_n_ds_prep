#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int> >& A, vector<vector<int> >& B) {
		vector<int> ia(A.size(), 0);
		vector<int> ib(B.size(), 0);
		for(int i=0; i<A.size(); i++)
			for(int j=A.size()-1; j>=0; j--)
			{
				ia[i]=ia[i]<<j;
				ia[i]|=A[i][j];
			}

		for(int i=0; i<ia.size(); i++)
			cout << bitset<8>(ia[i]) << endl; 
		// send out the return value
		return 0;
    }
};


int main()
{
	Solution sol;
	int res=0;
	vector<vector<int> > imageA(3, vector<int>(3));
	imageA = {{1, 1, 0}, {0,1,1}, {0,1,0}};
	vector<vector<int> > imageB(3, vector<int>(3));
	imageB = {{0, 0, 0}, {0,1,1}, {0,0,1}};
	
	res = sol.largestOverlap( imageA, imageB );
	cout << res << endl;
	
	return 0;
}
