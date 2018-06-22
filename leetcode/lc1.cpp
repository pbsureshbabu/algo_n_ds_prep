#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool sortbyfirst( const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}


class Solution {
public:
    vector<int> results;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector< pair<int, int> > npairs(nums.size());
        for(unsigned int i=0; i<npairs.size(); i++)
        {
            npairs[i].first = nums[i];
            npairs[i].second = i;
        }

        sort(npairs.begin(), npairs.end(), sortbyfirst);

        int l=0;
        int r=npairs.size()-1;
        while(l<r)
        {
            if(npairs[l].first+npairs[r].first==target)
            {
                results.push_back(npairs[l].second);
                results.push_back(npairs[r].second);
                break;
            }
            else if(npairs[l].first+npairs[r].first>target)
                r--;
            else
                l++;
        }
        return results;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    input.push_back(11);
    input.push_back(7);
    input.push_back(2);
    input.push_back(15);
    int target=9;
    vector<int> result(2);

    result = sol.twoSum(input, target);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}