// is it a sorted array?
// does it have negative and positive numbers including 0's?
// are all the nos unique?
// does the numbers have a range?
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search( vector<int> &nums, int b, int e, int val )
{
	if(b>e || e<b || val<nums[b] || val>nums[e])
		return -1;
	
	int m=(b+e)/2;
	
	if(nums[m]==val)
		return m;
	else if( nums[m]>val )
		return binary_search( nums, b, m, val );
	else
		return binary_search( nums, m+1, e, val );
}

int main()
{
	vector<int> nums(10);
	for(int i=0; i<10; i++)
		nums[i] = i*2;

	int result = -1;
	result = binary_search( nums, 0, 9, 10 );
	cout << result << endl;

	result = binary_search( nums, 0, 9, 15 );
	cout << result << endl;

	result = binary_search( nums, 0, 9, 20 );
	cout << result << endl;

	result = binary_search( nums, 0, 9, 18 );
	cout << result << endl;

	vector<int> test(5);
	test[0] = 15;
	test[1] = -3;
	test[2] = 2;
	test[3] = 11;
	test[4] = 7;

	sort( test, test+4);
	for(int i=0; i<5; i++)
		cout << test[i] << " ";
	cout << endl;
	
	return 0;
}
