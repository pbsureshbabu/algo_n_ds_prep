#include <iostream>
#include <vector>
using namespace std;


void qs( vector<int> &arr, int begin, int end )
{
	int b = begin;
	int e = end-1;
	int p = end;
	
	if(b>=e)
		return;

	while( b<e )
	{
		while(b<e)
			if(arr[b]<=arr[p])
				b++;
			else
				break;
		while( e>=b )
			if( arr[e]>arr[p])
				e--;
			else
				break;
		{ int temp=arr[b]; arr[b]=arr[e]; arr[e]=temp; }
	}
	{ int temp=arr[b]; arr[b]=arr[p]; arr[p]=temp; }
	for( int i=0; i<10; i++ )
		cout << arr[i] << " ";
	cout << endl;
	qs( arr, begin, b-1, b);
	qs( arr, b+1, end, end+1 );
}

int main()
{
	vector<int> nums(10);
	nums[0] = 5;
	nums[1] = -5;
	nums[2] = 3;
	nums[3] = 2;
	nums[4] = 8;
	nums[5] = 1;
	nums[6] = -15;
	nums[7] = -7;
	nums[8] = 0;
	nums[9] = 1;

	qs( nums, 0, 8, 9);
	for( int i=0; i<10; i++ )
		cout << nums[i] << " ";
	cout << endl;
		
	return 0;
}
