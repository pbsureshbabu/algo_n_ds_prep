#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
	{
		int r1x1=rec1[0];
		int r1y1=rec1[1];
		int r1x2=rec1[2];
		int r1y2=rec1[3];
		int r2x1=rec2[0];
		int r2y1=rec2[1];
		int r2x2=rec2[2];
		int r2y2=rec2[3];

		if((r1x2<=r2x1) || (r1x1>=r2x2))
		{
			cout << "x is outside" << endl;
			return false;
		}
		else if((r1y2<=r2y1)||(r1y1>=r2y2))
		{
			cout << "y is outside" << endl;
			return false;
		}
		else 
			return true;
    }
};


int main()
{
	Solution sol;
	bool res;
	
	vector<int> rec1;
	vector<int> rec2;
	vector<int> rec3;
	vector<int> rec4;
	rec1={7,8,13,15};
	rec2={10,8,12,20};
	rec3={0,0,1,1};
	rec4={1,0,2,1};

	res=sol.isRectangleOverlap(rec1, rec2);
	//res=sol.isRectangleOverlap(rec3, rec4);
	cout << res << endl;
	
	return 0;
}
