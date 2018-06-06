#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<pair<int,int> > insertion_sort( vector<pair<int, int> > &numspairs)
	{
		int i;
		pair<int, int> key;
		int j;
		for(i=1; i<numspairs.size(); i++)
		{
			key = numspairs[i];
			j = i-1;
			while(j>=0 && numspairs[j].first>key.first)
			{
				numspairs[j+1]=numspairs[j];
				j=j-1;
			}
			numspairs[j+1]=key;
		}
		return numspairs;
	}
	vector<int> sort( vector<int> &nums )
	{
		vector<pair<int, int> >numspairs(nums.size());
		vector<pair<int, int> >resnumspairs(0);
		int i;
		
		for(i=0; i<nums.size(); i++)
		{
			numspairs[i].first = nums[i];
			numspairs[i].second = i;
		}

		for(i=0; i<nums.size(); i++)
			cout << numspairs[i].second << ":" << numspairs[i].first << endl;

		resnumspairs = insertion_sort( numspairs );

		for(i=0; i<nums.size(); i++)
			cout << resnumspairs[i].second << ":" << resnumspairs[i].first << endl;
		return nums;
	}
};

int main()
{
	int i;
	vector<int> nums(0);
	vector<int> result(0);
	nums = {4, 3, 10, 1, 40, 7, 9, 12, 56};
	
	Solution sol;
	result = sol.sort( nums );

	for(i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}
