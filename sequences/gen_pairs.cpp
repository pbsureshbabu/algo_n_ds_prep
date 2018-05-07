#include <iostream>
#include <vector>
using namespace std;

void gen_pairs( vector<int> &nums )
{
	int size = nums.size();
	for( int i=0; i<size-1; i++ )
		for( int j=i+1; j<size; j++ )
			cout << "(" << nums[i] << "," << nums[j] << ")" << endl;
}

int main()
{
	vector<int> nums(6);
	nums[0] = 4;
	nums[1] = 3;
	nums[2] = 2;
	nums[3] = 1;
	nums[4] = 7;
	nums[5] = 8;
	gen_pairs( nums );
	return 0;
}
