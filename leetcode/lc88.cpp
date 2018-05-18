// prob #88 - merge two sorted arrays

// lessons learned
// 1. you need to sleep well :-)
// 2. lots of errors introduced in the tiny problem.
// 3. think through each and every line.
// 4. the entire code you write will be only 25 to 30 lines.
// 5. so think through each line and write and will be easy to debug
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
    	int wi=m+n-1, ri=m-1;
		while(ri>=0)
			nums1[wi--]=nums1[ri--];
		while(wi>=0)
			nums1[wi--]=0;

		wi=0;
		int n1ri=n, n2ri=0;
		while(n1ri<(m+n) && n2ri<n)
			if(nums1[n1ri]<nums2[n2ri])
				nums1[wi++]=nums1[n1ri++];
			else
				nums1[wi++]=nums2[n2ri++];

		while(n1ri<m)
			nums1[wi++]=nums1[n1ri++];
		while(n2ri<n)
			nums1[wi++]=nums2[n2ri++];
    }
};


int main()
{
	Solution sol;
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(6);
	
	sol.merge(nums1, 3, nums2, 3);

	for(int i=0; i<nums1.size(); i++)
		cout << nums1[i] << " ";
	cout << endl;
	
	return 0;
}
