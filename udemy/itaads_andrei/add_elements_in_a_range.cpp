/*
It's given an array (indexed from 1) of N elements on which we make M queries:

add(Left, Right, X) - all the elements between the position Left and Right (1<=Left<=Right<=N) are raising their values with X.

After all the operations are completed, print the array.

example

Array: 1 1 1 4 5 6

operations: (1, 5, 2), (2, 3, 10)

Final array: 3 13 13 6 7 6
*/

// Possible questions that can be asked
// 1. can I modifiy the existing array?
// 2. can I use addition space in the order of n
// 3. assuming there are k queries, the timecomplexity will be O(kn) if o(n) space is not used
// 4. on using O(n) space, the time complexity can be brought down to O(k+n)


#include <bits/stdc++.h>
using namespace std;

ifstream myin("data.in");
ofstream myout("data.out");

int main()
{
	// getting the inputs
    int n=0;
    myin >> n;
    if(n==0)
        return 0;
    vector<int> vint(n+1, 0);
    for(int i=1; i<=n; i++)
        myin >> vint[i];

	// the core of the algorithm
    vector<int> vtempint(n+1, 0);
    int l=0, r=0, x=0;
    while(1)											// O(k)
    {
        l=0; r=0; x=0;
        myin >> l >> r >> x;
        // assuming 1<=l<=r<=n 
        if(l==0 || r==0)
            break;
        vtempint[l]+=x;
        if(r+1<=n)
            vtempint[r+1]-=x;
    }

	//printing the outputs
    int sum=0;
    for(int i=1; i<=n; i++)								// O(n)
    {
        sum+=vtempint[i];
        myout << vint[i]+sum << " ";
    }
    myout << endl;
    return 0;    
}
