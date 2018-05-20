// leetcode prob #839 - group the strings as per the given description.

// understand disjoint sets better, like union, set, find etc
// since this is the first problem, there were lots of errors and great learning
// come back to this problem and submit it again for getting accepted

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// Looks like, the way in which I was doing the union is wrong.
// Since, it is the first implementation and not good in c++, offcourse there were issues.


typedef struct mynode_
{
	int val;
	struct mynode_ *root;
	struct mynode_ *child;
} mynode_t;

class Solution {
	int group_cnt;
public:
	bool is_same_group( string s1, string s2 )
	{
		int pos1=-1;
		int pos2=-1;
		for(int i=0; i<s1.size(); i++)
		{
			if(s1[i]!=s2[i])
			{
			    if(pos1<0)
					pos1=i;
				else if(pos2<0)
					pos2=i;
				else
					return false;
			}
		}
		return true;
	}

	// there is room for optimization
	void myunion( vector<mynode_t *> &np, int n1, int n2 )
	{
		cout << n1 << " " << n2 << endl;
		np[n2]->root = np[n1]->root;
		mynode_t *temp;
		temp=np[n1];
		while(temp)
		{
			if(temp->child==NULL)
			{
				temp->child=np[n2];
				break;
			}
			temp=temp->child;
		}
		group_cnt--;
	}
	
    int numSimilarGroups(vector<string>& A) 
	{
		group_cnt=A.size();
		cout << A.size() << endl;

		// setting up the groups
		vector<mynode_t> nodes(A.size());
		for(int i=0; i<nodes.size(); i++)
		{
			nodes[i].val=i;
			nodes[i].root=&nodes[i];
			nodes[i].child=NULL;
		}
		vector<mynode_t *> nodesp(A.size());
		for(int i=0; i<nodesp.size(); i++)
			nodesp[i]=&nodes[i];

		// the core of the algo		
		for(int i=0; i<A.size(); i++)
		{
			for(int j=i+1; j<A.size(); j++)
			{
				bool is_same = is_same_group(A[i], A[j]);
				//cout << A[i] << " " << A[j] << " " << is_same << endl;
				if(is_same)
				{
					myunion(nodesp, i, j);
				}
			}
		}

		// returning the group size
        return group_cnt;
    }
};



int main()
{
	Solution sol;
	int res=0;
	
	vector<string> A;
	//A={"tars", "rats", "arts", "star"};
	//A={"ufixvnxsdxalinayfaappbmmj","nxpxiaauvyjxasbfmfinmdpla","ujimiyxsaxpavnanfapmlbxdf","ufimvyxsaxpainanfapdlbxmj","nxpyajaumxixalbfvpdnmasfi","nxpxiaauvyjxpsbfmfinmdala","ufimvyxspxaainanfapdlbxmj","nxpyaiaumxjxapbfvlanmdsfi","ufimvyxspxapinanfaadlbxmj","nxpyaaauvxjxasbfmfinmdpli","nxpyajaumxixapbfvlanmdsfi","nxpyaaaumxjxasbfvfinmdpli","ufixvnbsdxalinayfamppxamj","ujimvyxsaxpainanfapdlbxmf","ufixvyxsdxalinanfaappbmmj","nxpyaaaumxjxapbfvlinmdsfi","ufixvyxspxalinanfaadpbmmj","nxpyaaaumxjxasbfvlinmdpfi","ufixvyxspxapinanfaadlbmmj","ufixvnbsdxalinayfaappxmmj","ufiavnbsdxxlinayfamppxamj","nxpyajaumxixapbfvldnmasfi","ufiavnbsdxxlinayfamppxajm","nxpyiaauvxjxasbfmfinmdpla","ujimiyxsaxpavnanfapdlbxmf"};
	A={"qihcochwmglyiggvsqqfgjjxu","gcgqxiysqfqugmjgwclhjhovi","gjhoggxvcqlcsyifmqgqujwhi","wqoijxciuqlyghcvjhgsqfmgg","qshcoghwmglygqgviiqfjcjxu","jgcxqfqhuyimjglgihvcqsgow","qshcoghwmggylqgviiqfjcjxu","wcoijxqiuqlyghcvjhgsqgmgf","qshcoghwmglyiqgvigqfjcjxu","qgsjggjuiyihlqcxfovchqmwg","wcoijxjiuqlyghcvqhgsqgmgf","sijgumvhqwqioclcggxgyhfjq","lhogcgfqqihjuqsyicxgwmvgj","ijhoggxvcqlcsygfmqgqujwhi","qshcojhwmglyiqgvigqfgcjxu","wcoijxqiuqlyghcvjhgsqfmgg","qshcojhwmglyiggviqqfgcjxu","lhogcgqqfihjuqsyicxgwmvgj","xscjjyfiuglqigmgqwqghcvho","lhggcgfqqihjuqsyicxgwmvoj","lhgocgfqqihjuqsyicxgwmvgj","qihcojhwmglyiggvsqqfgcjxu","ojjycmqshgglwicfqguxvihgq","sijvumghqwqioclcggxgyhfjq","gglhhifwvqgqcoyumcgjjisqx"};

	res=sol.numSimilarGroups(A);
	cout << res << endl;
	
	return 0;
}
