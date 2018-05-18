// Leetcode prob #21 - Merge two sorted lists

// lessons learned
// 1. be careful w/ the pointers
// 2. it is better to put some diagram of the data structure instead of keeping in memory
// 3. it is called cognitive outsourcing.

#include <iostream>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *res=NULL, *resh=NULL, *t=NULL;
		while(l1 && l2)
		{
			if(l1->val<=l2->val) {t=l1; l1=l1->next;}
			else {t=l2; l2=l2->next;}

			if(!res) {res=t;resh=t;}
			else {res->next=t; res=res->next;}
		}
		if(l1) t=l1;
		else t=l2;

		if(!res) {res=t; resh=t;}
		else {res->next=t; res=res->next;}

		return resh;
    }
};


int main()
{
	Solution sol;
	ListNode *l1=NULL;
	ListNode *l2=NULL;
	ListNode *t=NULL;
	ListNode *res = NULL;
	
	t=new ListNode(1); l1 = t;
	t->next=new ListNode(2);t=t->next;
	t->next=new ListNode(4);t=t->next;
	t->next=new ListNode(5);

	t=NULL;
	t=new ListNode(1); l2 = t;
	t->next=new ListNode(3);t=t->next;
	t->next=new ListNode(4);

	t=l1;
	while(t) {
		cout << t->val << "->";
		t=t->next;
	}
	cout << endl;
	t=l2;
	while(t) {
		cout << t->val << "->";
		t=t->next;
	}
	cout << endl;

	res = sol.mergeTwoLists( l1, l2 );

	while(res) {
		cout << res->val << "->";
		res=res->next;
	}
	cout << endl;
	
	return 0;
}
