#include <iostream>
using namespace std;

#if 0
int arr[16][4] = {
/* 00 */ 0, 0, 0, 0,
/* 01 */ 3, 0, 0, 0,
/* 02 */ 0, 0, 0, 0,
/* 03 */ 0, 1, 1, 0,
/* 04 */ 1, 0, 1, 0,
/* 05 */ 0, 1, 1, 0,
/* 06 */ 0, 0, 1, 0,
/* 07 */ 0, 2, 0, 0,
/* 08 */ 0, 2, 0, 0,
/* 09 */ 0, 2, 1, 0,
/* 10 */ 1, 0, 0, 0,
/* 11 */ 0, 0, 0, 0,
/* 12 */ 0, 0, 0, 0,
/* 13 */ 0, 0, 0, 0,
/* 14 */ 0, 0, 0, 0,
/* 15 */ 0, 0, 0, 0,
};

int res[16][4];
#endif

int max_value( int a, int b )
{
	return a>b?a:b;
}

int ts( int **arr, int **res, int N, int height, int I, int cr, int cc )
{
	// Base case
	if( cr<0 )
		return 0;
	if( cr==0 )
		return arr[cr][cc];

	if(res[cr][cc] != -1)
		return res[cr][cc];

	// Recursive case
	int max=-1;
	for(int i=0; i<N; i++)
	{
		if(i==cc)
			max = max_value( max, ts(arr, res, N, height, I, cr-1, i));
		else
		{
			if((cr-I)>=0)
				max = max_value( max, ts(arr, res, N, height, I, cr-I, i));
		}
	}

	res[cr][cc] = max+arr[cr][cc];
	//cout << cr << ":" << cc << " = " << res[cr][cc] << endl;

	return res[cr][cc];
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	int H;
	int I;

	cin >> N;
	cin >> H;
	cin >> I;

	// for getting the input values
	int **ary = new int*[H+1];
	for(int i=0; i<H+1; i++)
		ary[i] = new int[N];

	for( int i=0; i<H+1; i++)
		for( int j=0; j<N; j++)
			ary[i][j] = 0;

	// for storing the temporary results
	int **res = new int*[H+1];
	for(int i=0; i<H+1; i++)
		res[i] = new int[N];

	for( int i=0; i<H+1; i++)
		for( int j=0; j<N; j++)
			res[i][j] = -1;


	for( int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		for(int j=0; j<temp; j++)
		{
			int t;
			cin >> t;
			ary[t][i]++;
		}
	}

	int max = 0;
	for( int i=0; i<N; i++)
		max = max_value( max, ts( ary, res, N, H, I, H, i ));

	cout << max << endl;
	return 0;
}
