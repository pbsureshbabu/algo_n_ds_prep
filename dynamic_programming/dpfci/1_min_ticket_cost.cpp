// -there are n stations in a route, starting from 0 to n-1.
// -a train moves from first station(0) to last station (n-1) in only forward direction.
// -the cost of tickets between any two stations is given.
// -find the minimum cost of travel from station s to station d.
#include <iostream>
#include <vector>
using namespace std;

#define MAX_STATIONS   (4)

int cost[MAX_STATIONS][MAX_STATIONS] = {  {0, 10, 75, 94},
                    {-1, 0, 35, 50},
                    {-1, -1, 0, 80},
                    {-1, -1, -1, 0}
                 };
int cache[MAX_STATIONS][MAX_STATIONS];

int mincost_helper( int s, int d)
{
    // base case
    if(s==d)
        return 0;
    if(s+1==d)
        return cost[s][d];
    if(cache[s][d]!=-1)
        return cache[s][d];

    // recursive case
    int mcost=cost[s][d];
    for(int i=s+1; i<d; i++)
    {
        mcost = min( mcost, mincost_helper(s, i) + mincost_helper(i,d) );
    }
    return mcost;
}

int mincost(int s, int d)
{
    for(int i=0; i<=d; i++)
        for(int j=0; j<=d; j++)
            cache[i][j] = -1;
    return mincost_helper(s, d);
}

int main()
{
    int result;

    result = mincost(0, 3);
    cout << result << endl;

    return 0;
}

