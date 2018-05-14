// 46. permute a collection of distinct integers, return all possible integers

// lessons learned
// 1. understand what is the output
// 2. don't jump into printing or something
// 3. vector of vectors and how they are initialized; revisit it
// 4. changing the class little bit by introducing the helper function and data members



#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	vector<vector<int> > res;
	vector<vector<int> > permute( vector<int> &nums )
	{
		vector<int> cnt(nums.size());
		for(int i=0; i<cnt.size(); i++)
			cnt[i]=1;
		vector<int> res1(nums.size());

		permute_helper(nums, cnt, this->res, res1, 0);
		return res;
	}
private:
	void permute_helper( vector<int> &arr, vector<int> &cnt, 
						 vector<vector<int> > &res, vector<int> res1, int lvl)
	{
		// base case
		if( lvl==arr.size() )
		{
			res.resize(res.size()+1, vector<int>(cnt.size()));
			for(int i=0; i<res1.size(); i++)
				res[res.size()-1][i]=res1[i];
			return;
		}
	
		// recursive case
		for(int i=0; i<arr.size(); i++)
		{
			if(cnt[i]!=0)
			{
				res1[lvl]=arr[i];
				cnt[i]=0;
				permute_helper( arr, cnt, res, res1, lvl+1 );
				cnt[i]=1;
			}
		}
	}
};


int main()
{
	class solution sol;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int> > res;

	res = sol.permute( nums );
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}

