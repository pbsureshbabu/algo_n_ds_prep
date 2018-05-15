// 49. group anagrams 

// lessons learned
// 1. take care of the indexes of the strings
// 2. go through all the cases 
// 3. problem looks simple, but implementing it seems to be giving lots of bugs

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
vector<vector<string> > res;
vector<vector<string> > groupAnagrams(vector<string>& strs) 
{
	vector<int> pa(26);
	vector<vector<int> > pg(0, vector<int>(26));

	for(int i=0; i<strs.size(); i++)
	{
		for(int j=0; j<26; j++) pa[j]=0;
		for(int j=0; j<strs[i].size(); j++)
		{
			int t=strs[i][j]-'a';
			if(t<0 && t >25) {cout << "invalid input" << endl; return this->res;}
			pa[t]++;
		}

		bool is_anagram = false;
		bool is_new = true;
		for(int j=0; j<pg.size(); j++)
		{
			int k;
			for(k=0; k<26; k++)
				if(pa[k]!=pg[j][k]) 
					break;
			if(k==26) // there is a pattern match
			{
				//cout << i << " it is anagram of " << j << endl;
				is_anagram = true;
				is_new = false;
				if(res.size()<=j)
				{
					res.resize(res.size()+1, vector<string>(0));
					res[res.size()-1].push_back(strs[i]);
				}
				else
					res[j].push_back(strs[i]);
			}
		}

		if(is_new==true)
		{
			res.resize(res.size()+1, vector<string>(0));
			res[res.size()-1].push_back(strs[i]);
		}
		
		if( is_anagram==false )
		{
			pg.resize(pg.size()+1, vector<int>(26));
			for(int j=0; j<26; j++)
				pg[pg.size()-1][j]=pa[j];
		}
	}
	return res;
}
};


int main()
{

	Solution sol;
	vector<vector<string> > res;
	vector<string> strs;
	
	strs.push_back( "eat" );
	strs.push_back( "tea" );
	strs.push_back( "tan" );
	strs.push_back( "ate" );
	strs.push_back( "nat" );
	strs.push_back( "bat" );

	res = sol.groupAnagrams( strs );
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}

