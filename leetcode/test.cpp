#include <iostream>
#include <vector>
using namespace std;


bool is_lch( int pos )
{ 
	if(pos&1==1) 
		return true;
	return false;
}

void heapsort( vector<int> &nums )
{
	int p=0;

	for(int i=nums.size()-1; i>0; i--)
	{
		if(is_lch(i))
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

int main()
{
	vector<int> nums;

	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(6);

	heapsort( nums );

	for(int i=0; i<nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

	vector<int> seq;
	vector<int> cnt;
	group_elements( nums, seq, cnt );
	for(int i=0; i<seq.size(); i++)
		cout << seq[i] << " ";
	cout << endl;
	for(int i=0; i<cnt.size(); i++)
		cout << cnt[i] << " ";
	cout << endl;
	
	return 0;
}
