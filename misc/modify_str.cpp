// lessons learned
// 1. be careful w/ stl .size(). Have the parenthesis.
// 2. also be careful w/ converting character into a lut
// 3. characters can be added to the string container by + operator like 
//    string s1;
//    s1+='c'; 

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

void modify_seq( string s )
{
	vector<char> seq(26);
	vector<int> cnt(26);
	int seqindex=0;

	for(int i=0; i<s.size(); i++)
	{
		if(cnt[s[i]-'a']==0)
		{
			seq[seqindex]=s[i];
			seqindex++;
		}
		cnt[s[i]-'a']++;
	}

	string res;
	for(int i=0; i<seqindex; i++)
		for(int j=0; j<cnt[seq[i]-'a']; j++)
		{
			res+=seq[i];
		}
	cout << res << endl;
}

int main()
{
	string s1("kick");
	string s2("madam");
	
	modify_seq( s1 );
	modify_seq( s2 );

	return 0;
}
