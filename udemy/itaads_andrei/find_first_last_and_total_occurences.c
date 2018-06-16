// finding first or last occurence of a number

#include <bits/stdc++.h>
using namespace std;

ifstream myin("data.in");
ofstream myout("data.out");

int first_occurence( vector<int> &arr, int key ) // O(log n)
{
    int l=0;
    int r=arr.size()-1;
    int result=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(key==arr[m])
        {
            result=m;
            r=m-1;
        }
        else if(key>arr[m])
            l=m+1;
        else 
            r=m-1;
    }
    return result;
}

int last_occurence( vector<int> &arr, int key ) // O(log n)
{
    int l=0;
    int r=arr.size()-1;
    int result=-1;
    while(l<=r)
    {
        int m =(l+r)/2;
        if(key==arr[m])
        {
            result=m;
            l=m+1;
        }
        else if(key>arr[m])
            l=m+1;
        else
            r=m-1;
    }
    return result;
}

int get_occurence_index( vector<int> &arr, int key, bool is_first_occur )
{
    int l=0;
    int r=arr.size()-1;
    int result=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(key==arr[m])
        {
            result=m;
            if(is_first_occur)
                r=m-1;
            else
                l=m+1;
        }
        else if(key>arr[m])
            l=m+1;
        else 
            r=m-1;
    }
    return result;
}

int total_occurences( vector<int> &arr, int key )  // O(log n + log n) which is O(log n)
{
    int first_occur = first_occurence(arr, key);
    int last_occur = last_occurence(arr, key);
    if(first_occur!=-1)
    {
        return last_occur-first_occur+1;
    }
    return 0;
}

int main()
{
    int n;
    myin >> n;
    vector<int> vint(n, 0);
    for(int i=0; i<n; i++)
        myin >> vint[i];
    int key;
    myin >> key;

    int first_occur = -1;
    first_occur = first_occurence( vint, key );
    myout << first_occur << endl;

    int last_occur = -1;
    last_occur = last_occurence( vint, key );
    myout << last_occur << endl;

    int total_occur = -1;
    total_occur = total_occurences( vint, key );
    myout << total_occur << endl;

    // w/ a different code base
    myout << "--------------" << endl;
    first_occur = -1;
    first_occur = get_occurence_index( vint, key, true );
    myout << first_occur << endl;

    last_occur = -1;
    last_occur = get_occurence_index( vint, key, false );
    myout << last_occur << endl;

    total_occur = 0;
    if(first_occur!=-1)
        total_occur = last_occur-first_occur+1;
    myout << total_occur << endl;

    
    return 0;
}
