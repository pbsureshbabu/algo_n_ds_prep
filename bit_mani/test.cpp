#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int count_bits( unsigned int x )
{
	int cnt=0;
	while(x)
	{
		if(x&1==1)
			cnt++;
		x=x>>1;
	}
	return cnt;
}

int bitposition( unsigned int x )
{
	if(x==0)
		return -1;
	
	int index=0;
	do
	{
		if(x&1==1)
			break;
		x=x>>1;
		index++;
	}while(x);
	
	return index;
}

bool is_palindrome( string s )
{
	int l=0;
	int r=s.length()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
			return false;
		l++; r--;
	}
	return true;
}

int main()
{
	string s="Are we not pure? “No sir!” Panama’s moody Noriega brags. “It is garbage!” Irony dooms a man; a prisoner up to new era";
	bool res=false;

	res = is_palindrome(s);
	cout<< res << endl;
	
	return 0;
}
