#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int x = -2;
	int n = 0;
	double res;
	double dx = x * (1.0);
	double dn = n * (1.0);
	res = pow(dx, dn);
	cout << sizeof(float) << endl;
	printf( "res=%f\n", res );
	return 0;
}
