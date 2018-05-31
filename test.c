#include <stdio.h>

typedef struct hs_info_
{
	unsigned int frame_no;
	unsigned int buf_status;
	unsigned int error;
}hs_info_t;
hs_info_t dem00[5] = {
		{10, 11, 12},
		{20, 21, 22},
		{30, 31, 32},
		{40, 41, 42},
		{50, 51, 52}
	};
hs_info_t dem01[5] = {
		{15, 16, 17},
		{25, 26, 27},
		{35, 36, 37},
		{45, 46, 47},
		{55, 56, 57}
	};

int main()
{
	hs_info_t *hs_info_ptr;
	hs_info_ptr = &dem01[0];
	int i;
	
	for(i=0; i<5; i++)
		printf( "%d,%d,%d\n", hs_info_ptr[i].frame_no,
							  hs_info_ptr[i].buf_status,
							  hs_info_ptr[i].error );

	return 0;
}
