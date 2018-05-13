// #42: Trapping rain water

// lessons learned
// 1. review the vector/array boundaries, whether anyelement outside is being accessed.
// 2. think about which one to have, whether max or -2 or 0 or min of -2 or 0.
// 3. go through some test cases.



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minvalue( int a, int b ) { return a<=b?a:b;}
int maxvalue( int a, int b ) { return a>b?a:b;}

int trap(vector<int>& height)
{
	if(height.size()<=2)
		return 0;
	
    int i=0;
	int j=height.size()-1;
	int lw=height[i];
	int rw=height[j];
	vector<int> res(height.size());
	res[0]=0;
	res[height.size()-1]=0;
	int maxminwh = 0;

	while(i<j)
	{
		lw=height[i];
		rw=height[j];

		//cout << i << ":" << j << endl;
		int minwh=minvalue( lw, rw );
		if(minwh>maxminwh)
		{
			for(int k=i+1; k<j; k++)
				res[k]+=(minwh-maxminwh);
			maxminwh = minwh;
		}
		if(lw<=rw)
		{
			i++;
			res[i]=maxvalue( 0, res[i]-height[i] );
		}
		else
		{
			j--;
			res[j]=maxvalue( 0, res[j]-height[j] );
		}
	}

	int tu=0;
	for( int k=0; k<height.size(); k++ )
	{
		//cout << res[k] << " ";
		tu+=res[k];
	}
	//cout << endl;

	return tu;
}



int main()
{
	vector<int> height;
	height.push_back(4);
	height.push_back(2);
	height.push_back(0);
	height.push_back(3);
	height.push_back(2);
	height.push_back(5);
	//height.push_back(1);
	//height.push_back(3);
	//height.push_back(2);
	//height.push_back(1);
	//height.push_back(2);
	//height.push_back(1);
	
	int result = trap( height );
	cout << result << endl;
	
	return 0;
}
