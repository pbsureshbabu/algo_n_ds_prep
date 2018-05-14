// 47. permute a collection of integers, there coule be duplicates, return all possible integers

// lessons learned


#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	vector<vector<int> > res;
	vector<vector<int> > permute( vector<int> &nums )
	{
		vector<int> cnt;
		vector<int> seq;
		vector<int> res1(nums.size());
		
		heapsort(nums);
		group_elements(nums, seq, cnt);
		permute_helper(seq, cnt, this->res, res1, 0, nums.size());
		return res;
	}
private:
	void permute_helper( vector<int> &arr, vector<int> &cnt, 
						 vector<vector<int> > &res, vector<int> res1, int lvl, int lastlvl)
	{
		// base case
		if( lvl==lastlvl )
		{
			res.resize(res.size()+1, vector<int>(lastlvl));
			for(int i=0; i<res1.size(); i++)
				res[res.size()-1][i]=res1[i];
			return;
		}
	
		// recursive case
		for(int i=0; i<lastlvl; i++)
		{
			if(cnt[i]!=0)
			{
				res1[lvl]=arr[i];
				cnt[i]--;
				permute_helper( arr, cnt, res, res1, lvl+1, lastlvl );
				cnt[i]++;
			}
		}
	}

	void group_elements( vector<int> &nums, vector<int> &seq, vector<int> &cnt )
	{
		if(nums.size()==0)
			return;
		int seqindex=0;
		seq.push_back(nums[0]);
		cnt.push_back(1);

		int curele = nums[0];
		for(int i=1; i<nums.size(); i++)
		{
			if(nums[i]==curele)
			{
				cnt[cnt.size()-1]++;
			}
			else
			{
				curele=nums[i];
				seq.push_back(curele);
				cnt.push_back(1);
			}
		}
	}

	void heapsort( vector<int> &nums )
	{
		int p=0;

		for(int i=nums.size()-1; i>0; i--)
		{
			if(i&1==1)
				p=(i-1)/2;
			else
				p=(i-2)/2;
			if( nums[p]<nums[i] )
			{
				int t = nums[p];
				nums[p] = nums[i];
				nums[i] = t;
			}
		}

		int le=nums.size()-1;
		while(le!=0)
		{
			int t = nums[0];
			nums[0] = nums[le];
			nums[le] = t;
			le--;
			
			p=0;
			int lch=2*p+1;
			int rch=2*p+2;
			while(p<le)
			{
				lch=2*p+1;
				rch=2*p+2;
				if(rch<=le) // parent has both left and right childs
				{
					if(nums[p]<nums[lch] || nums[p]<nums[rch])
					{
						if(nums[lch]>=nums[rch])
						{
							t=nums[lch];
							nums[lch]=nums[p];
							nums[p]=t;
							p=lch;
						}
						else
						{
							t=nums[rch];
							nums[rch]=nums[p];
							nums[p]=t;
							p=rch;
						}				
					}
					else
						break;
				}
				else if(lch<le) // parent has only left child
				{
					if(nums[p]<nums[lch])
					{
						t=nums[p];
						nums[p]=nums[lch];
						nums[lch]=t;
						p=lch;
					}
					else
						break;
				}
				else
					break;
			}
		}
	}
};


int main()
{
	class solution sol;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	//nums.push_back(2);
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
