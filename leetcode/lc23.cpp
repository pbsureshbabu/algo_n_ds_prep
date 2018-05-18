// Leetcode prob #23 - Merge k sorted lists

// lessons learned
// 1. analyse different time complexities
// 2. and also general coding complexities
// 3. handle the null inputs

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        while(lists.size()>=2)
        {
        	ListNode *t1 = lists[lists.size()-1];
			ListNode *t2 = lists[lists.size()-2];
			ListNode *res=NULL;
			lists.pop_back();
			lists.pop_back();
			res=mergeTwoLists(t1, t2);
			lists.push_back(res);
        }
		if(lists.size()==0)
			return NULL;
		else
			return lists[0];
    }
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
	vector<ListNode*> lists;
	vector<ListNode*> lists1;
	ListNode *res=NULL;

	ListNode *t = new ListNode(1);
	lists.push_back(t);
	t->next=new ListNode(4);t=t->next;
	t->next=new ListNode(5);
	
	t=new ListNode(1);
	lists.push_back(t);
	t->next=new ListNode(3);t=t->next;
	t->next=new ListNode(4);
	
	t=new ListNode(2);
	lists.push_back(t);
	t->next=new ListNode(6);

	for(int i=0; i<lists.size(); i++)
	{
		t=lists[i];
		while(t) {cout << t->val << "->"; t=t->next;}
		cout << endl;
	}


	res = sol.mergeKLists(lists1);
	while(res) {
		cout << res->val << "->";
		res=res->next;
	}
	cout << endl;
	
	return 0;
}

