// #41: First missing positive integer

// lessons learned
// 1. use the header climits for INT_MAX and INT_MIN
// 2. check the input parameters and validity
// 3. also check the values in the intermediate code where you will 
//    think that the code before has changed from the initial value.
// 4. vector stl
// 5. while updating the lookup table, use the arr value instead of indexes
//    as it was intended to be.



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int firstMissingPositive( vector<int>& nums ) 
{
    if(nums.size()==0)
        return 1;
    int max=INT_MIN;
	//cout << max << endl;
	//cout << nums.size() << endl;

	for(int i=0; i<nums.size(); i++)
	{
		if(nums[i]>0 && nums[i]>max)
			max=nums[i];
	}

    if(max==INT_MIN)
        return 1;
	//cout << max << endl;
	int lut[max+1];
	for(int i=0; i<nums.size(); i++)
	{
		if(nums[i]>0)
			lut[nums[i]]=1;
	}

	for(int i=1; i<=max; i++)
		if(lut[i] != 1)
			return i;

	return max+1;
}



int main()
{
	int value;
	vector<int> ia;
	ia.push_back(7);
	ia.push_back(8);
	ia.push_back(9);
	ia.push_back(11);
	ia.push_back(12);
	
	value = firstMissingPositive( ia );
	cout << value << endl;
	
	return 0;
}
