#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort_rev( vector<int> &arr )
{
	int i, j, key;
	for( i=1; i<arr.size(); i++ )
	{
		key = arr[i];
		j=i-1;
		while( j>=0 && arr[j]<key )
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
	return arr;
}

vector<int> insertion_sort( vector<int> &arr )
{
	int i;
	for(i=1; i<arr.size(); i++)
	{
		int key;
		key = arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
	return arr;
}

int main()
{
	vector<int> arr(10);
	vector<int> result;

	arr = {4, 7, 9, 4, 6, 1, 2, 0, 8, 5};
	result = insertion_sort( arr );
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;

	arr = {4, 7, 9, 4, 6, 1, 2, 0, 8, 5};
	result = insertion_sort_rev( arr );
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	
	
	return 0;
}
