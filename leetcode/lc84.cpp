#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
	{
		int gmax=0;

		int max_height=0;
		for(int i=0; i<heights.size(); i++)
			if(heights[i]>max_height)
				max_height=heights[i];

		for(int i=1; i<=max_height; i++)
		{
			int cnt=0, max=0;
			for(int j=0; j<heights.size(); j++)
			{
				if(heights[j]-i>=0)
					cnt++;
				else
				{
					max=cnt>max?cnt:max;
					cnt=0;
				}
			}
			max=cnt>max?cnt:max;
			max=max*i;
			gmax=max>gmax?max:gmax;
		}
		
    	return gmax;    
    }
};


int main()
{
	Solution sol;
	int res=0;
	vector<int> heights;
	heights = {2,1,5,6,2,3};

	res=sol.largestRectangleArea(heights);
	cout << res << endl;
	
	return 0;
}
