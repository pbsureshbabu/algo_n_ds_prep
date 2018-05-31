#include <iostream>
using namespace std;

static unsigned int lookup[100];

// if n is even, divide by 2
// if n is odd, multiply by 3 and add 1
// assumes that the n takes values from 1 to 1,000
unsigned int cycle_length( unsigned int n )
{
	// base case
	if(n<100 && lookup[n]!=0) {return lookup[n];}
	if(n==1) {lookup[1]=1; return lookup[n];}

	cout << n << endl;
	// recursive case
	if(n&1)
		lookup[n]=1+cycle_length((n*3)+1);
	else
		lookup[n]=1+cycle_length(n/2);
	return lookup[n];
}

unsigned int max_cycle_length_range( unsigned int lower, unsigned int upper )
{
	unsigned int max=0;
	unsigned int lo, up;
	if(lower<=upper)
		{lo=lower;up=upper;}
	else
		{lo=upper; up=lower;}
	for(int i=lo; i<=up; i++)
	{
		unsigned int local_max = cycle_length(i);
		if(max<local_max)
			max=local_max;
	}
	return max;
}

int main()
{
	lookup[1]=1;
	cout << cycle_length(22) << endl;
	cout << cycle_length(22) << endl;
	cout << cycle_length(22) << endl;
	return 0;
}
