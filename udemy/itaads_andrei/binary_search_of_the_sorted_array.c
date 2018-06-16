// binary search of a particular element in a sorted incresing array.
// it will return an index from 0 through n-1 if the key is found in the array
// it will return -1, if the key is not found in the array

#include <bits/stdc++.h>
using namespace std;

ifstream myin("data.in");
ofstream myout("data.out");

int binary_search( vector<int> &arr, int l, int r, int key)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(key==arr[m])
            return m;
        else if(key>arr[m])
            return binary_search(arr, m+1, r, key);
        else
            return binary_search(arr, l, m-1, key);
    }
    else
        return -1;
}

int main()
{
    int n;
    myin >> n;
    vector<int> vi(n, 0);
    for(int i=0; i<n; i++)
        myin >> vi[i];
    int key;
    myin >> key;

    int result = -1;
    result = binary_search( vi, 0, (vi.size()-1), key);

    myout << result;
    return 0;
}
