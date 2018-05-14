// 46. permute
// -given a collection of distinct integers, return all possible integers

// lessons learned
// 1. understand what is the output
// 2. don't jump into printing or something


#include <iostream>
#include <vector>
using namespace std;

void permute( vector<int> &arr, vector<int> &cnt, vector<int> &res, int lvl)
{
	// base case
	if( lvl==arr.size() )
	{
		static int first_time=1;
		if( first_time )
		{
			cout << endl << "  [";
			first_time=0;
		}
		else
			cout << "," << endl << "  [";
		for(int i=0; i<res.size(); i++)
		{
			if(i!=res.size()-1)
				cout << res[i] << ",";
			else
				cout << res[i];
		}
		cout << "]";
	}

	// recursive case
	for(int i=0; i<arr.size(); i++)
	{
		if(cnt[i]!=0)
		{
			res[lvl]=arr[i];
			cnt[i]=0;
			permute( arr, cnt, res, lvl+1 );
			cnt[i]=1;
		}
	}
}

void permute_wrapper( vector<int> &arr )
{
	vector<int> cnt(arr.size());
	vector<int> res(arr.size());
	for(int i=0; i<arr.size(); i++)
		cnt[i]=1;
	cout << "[";
	permute( arr, cnt, res, 0);
	cout << endl << "]" << endl;
}

int main()
{
	vector<int> nums;
	
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	permute_wrapper( nums );

	return 0;
}

