#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct sllnode_
{
	int val;
	struct sllnode_ *next;
} sllnode_t;


sllnode_t *create_node( int value )
{
	sllnode_t *temp;
	temp = (sllnode_t *)malloc(sizeof(sllnode_t));
	if(temp)
	{
		temp->val = value;
		temp->next = NULL;
	}
	return temp;
}

void delete_node( sllnode_t *node )
{
	if(node)
		free( node );
}

void print_sll( sllnode_t *head )
{
	while(head)
	{
		cout << head->val << "->";
		head=head->next;
	}
	cout << "(NULL)" << endl;
}

sllnode_t *reverse_sll( sllnode_t *head )
{
	sllnode_t *prev = NULL;
	sllnode_t *rhead = head;
	sllnode_t *cur = head;
	sllnode_t *next = NULL;
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

int main()
{
	sllnode_t *head;
	sllnode_t *rhead;
	
	head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);
	head->next->next->next->next = create_node(5);

	print_sll(head);
	rhead = reverse_sll(head);
	print_sll(rhead);
	
	return 0;
}
