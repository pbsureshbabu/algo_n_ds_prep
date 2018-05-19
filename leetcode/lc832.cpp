// Leetcode prob #832 - flipping an image
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
    	for(int i=0; i<A.size(); i++)
    	{
    		int b=0;
			int e=A[i].size()-1;
			while(b<=e)
			{
				if(b==e)
					A[i][b]=1-A[i][b];
				else
				{
					int t=A[i][b];
					A[i][b]=1-A[i][e];
					A[i][e]=1-t;
				}
				b++; e--;
			}
    	}
		return A;
    }
};


int main()
{
	Solution sol;
	vector<vector<int> > res;
	vector<vector<int> > image(3);
	image = {{0,1,0}, {0,0,1}, {0,1,1}};

	for(int i=0; i<image.size(); i++)
	{
		for(int j=0; j<image[i].size(); j++)
			cout << image[i][j];
		cout << endl;
	}

	res=sol.flipAndInvertImage(image);
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j];
		cout << endl;
	}
	
	return 0;
}
