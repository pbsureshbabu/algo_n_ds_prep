#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main()
{
	long long int frame_no = 10;
	char buffer[64];
	
	sprintf( buffer, "C:\\\\%d_dump.yuv", (int)frame_no );
	printf( "%s\n", buffer );
	
	return 0;
}
