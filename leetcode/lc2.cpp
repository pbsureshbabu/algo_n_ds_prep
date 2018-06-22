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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        int value=0;
        ListNode *result=NULL;
        ListNode *retList=NULL;
        while( l1 || l2 || carry )
        {
            value=0; 
            if(l1) {value+=l1->val; l1=l1->next;}
            if(l2) {value+=l2->val; l2=l2->next;}
            value+=carry;
            carry=value/10;
            value%=10;
            if(!result)
            {
                result = new ListNode(value);
                retList = result;
            }
            else
            {
                result->next = new ListNode(value);
                result=result->next;
            }
        }
        return retList;
    }
};

int main()
{
    Solution sol;
    ListNode *l1;
    ListNode *l2;
    ListNode *result;
    l1=new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2=new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *temp;
    temp=l1;
    while(temp)
    {
        cout << temp->val << "->";
        temp=temp->next;
    }
    cout << endl;
    temp=l2;
    while(temp)
    {
        cout << temp->val << "->";
        temp=temp->next;
    }
    cout << endl;

    result = sol.addTwoNumbers(l1, l2);

    while(result)
    {
        cout << result->val << "->";
        result=result->next;
    }
    cout << endl;
    
    return 0;
}