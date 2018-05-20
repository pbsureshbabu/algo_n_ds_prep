#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string pushDominoes(string dominoes) 
	{
    	int size=dominoes.size();
		int i=0;
		int li=-1, ri=-1;
		while(i<size)
		{
			if(dominoes[i]=='L')
			{
				li=i;
				if(ri==-1)
				{
					li--;
					while(li>=0 && dominoes[li]=='.')
					{
						dominoes[li]='L';
						li--;
					}
				}
				else
				{
					while(ri<li)
					{
						dominoes[ri]='R';
						dominoes[li]='L';
						ri++;
						li--;
					}
				}
				li=-1;
				ri=-1;
			}
			else if(dominoes[i]=='R')
			{
				if(ri!=-1)
					while(ri<i)
					{
						dominoes[ri]='R';
						ri++;
					}
				ri=i;
			}
			i++;
		}
		if(ri!=-1)
			while(ri<size)
			{
				dominoes[ri]='R';
				ri++;
    		}
		return dominoes;
    }
};

int main()
{
	Solution sol;
	string res;
	string ins=".L.R...LR..L..";
	string outs="LL.RR.LLRRLL..";
	string ins1="R.R.L";
	string outs1="RRR.L";

	res = sol.pushDominoes(ins1);
	if(res==outs1)
		cout << "success" << endl;
	else
		cout << "failure" << endl;
	
	return 0;
}

