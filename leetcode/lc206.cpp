#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
	
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
	{
    	ListNode *prev = NULL, *next = NULL;
		ListNode *rhead = head, *cur = head;
		while(cur)
		{
			next = cur->next;
			rhead->next = prev;
			prev = cur;
			cur = next;
			if(cur)
				rhead = cur;
		}
		return rhead;
	}
	void printList(ListNode *head)
	{
		while(head) 
			{cout << head->val << "->"; head=head->next;}
		cout << "(NULL)" << endl;
	}
};


int main()
{
	Solution sol;
	struct ListNode *head;
	struct ListNode *rhead;
	
	head = new ListNode(1);
	head->next = new ListNode(2);

	sol.printList(head);
	rhead=sol.reverseList(head);
	sol.printList(rhead);
	
	return 0;
}
