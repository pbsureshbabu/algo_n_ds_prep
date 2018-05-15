// #50 - implement the myPow(x,n)
//
// lessons learned
// 1. where ever there is room for optimization, optimize it.
// 2. use the previous values for computation
// 3. don't think too much about the formulas and stuff.
// 4. just think about the basic logic and ways to optimize it.
// 5. some problems look very trivial, but there is room for doing it in log n times.


#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

class Solution {
public:
double power_helper( vector<double> &lut_value,
					vector<int> &lut_exp, double x, int n )
{
	if(n==0) return 1.0;
	if(n==1) return x;
	for(int i=0; i<lut_exp.size(); i++)
		if(n==lut_exp[i])
			return lut_value[i];
		
	double res=1.0;
	res=power_helper( lut_value, lut_exp, x, n/2 );
	lut_exp.push_back(n/2);
	lut_value.push_back(res);
	res*=res;
	lut_exp.push_back((n/2)*2);
	lut_value.push_back(res);
	if(n&1==1)
		res*=x;
	
	return res;
}

double myPow(double x, int n) 
{
	 if(n==0) return 1.0;
	 if(x==0) return 0.0;

	 bool exp_sign=false;
	 bool res_sign=false;
	 double res=1.0;
	 vector<double> lut_value;
	 vector<int> lut_exp;

	 if(n<0) exp_sign=true;
	 n=abs(n);
	 if(x<0 && (n&1==1)) res_sign=true;
	 x=abs(x);

	res=power_helper( lut_value, lut_exp, x, n );	 

	 if(exp_sign)
	 	res=(1/res);
	 
	 if(res_sign)
	 	return res*(-1.0);
	 else
	 	return res;
}
};

int main()
{
	Solution sol;
	double x=2.0;
	int n=-2;
	double res;

	res = sol.myPow( x, n );
	printf( "res = %f\n", res );
	
	return 0;
}
