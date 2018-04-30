// printing a 32 bit number in binary
#include <iostream>
using namespace std;

void print_num_in_binary( unsigned int n )
{
	if(n==0)
	{
		cout << 0 << endl;
		return;
	}

	bool can_i_print = false;
	int i=31;
	while(i>=0)
	{
		if((n>>i)&1)
			can_i_print = true;
		if(can_i_print)
			cout << ((n>>i)&1);
		i--;
	}
	cout << endl;
}

int main()
{
	print_num_in_binary(10);
	print_num_in_binary(0xffffffff);
	print_num_in_binary(0);
	print_num_in_binary(0x80000000);
	print_num_in_binary(0x00000001);
	
	return 0;
}
