#include <stdio.h>
#include <malloc.h>


// Maximum depth to hold the roi_ids
// Should be greater than 1
#define MAX_HOLDING    (3)

// Finite roi ids for a given frame dimension. Similar to macro blocks
// The incoming roi_ids range is from 0 through 255 for this example
#define INVALID_ROI_VALUE    (-1)
#define MIN_ROI_VALUE        (0)
#define MAX_ROI_VALUE        (255)
#define MAX_ROI              (MAX_ROI_VALUE+1)


// Basic data structures for this module
typedef struct roi_node_
{
	int roi_id;
	struct roi_node_ *prev;
	struct roi_node_ *next;
} roi_node_t;

// For holding the allocated nodes
static roi_node_t *free_nodes[MAX_HOLDING];
static int free_nodes_index=-1;

static roi_node_t *roi_node_lookup[MAX_ROI]; // This acts as a O(1) lookup
static roi_node_t *tail = NULL;
static roi_node_t *head = NULL;



// Initialization routine
void init_roi_updater()
{
	int i;
	for(i=0; i<MAX_HOLDING; i++)
	{
		roi_node_t *cur = (roi_node_t *)malloc(sizeof(roi_node_t));
		
		if(!cur) { printf( "Error: Allocating memory to the free nodes\n" ); continue; }
		else { cur->roi_id = INVALID_ROI_VALUE; cur->prev = NULL; cur->next = NULL;	}
		
		free_nodes[i]=cur;
	}
	free_nodes_index = 0;

    for(i=0; i<MAX_ROI; i++) { roi_node_lookup[i] = NULL; }
	head = NULL;
	tail = NULL;
}

// Deinitialization routine
void deinit_roi_updater()
{
	int i;
	for(i=0; i<MAX_HOLDING; i++)
	{
		if(free_nodes[i]) { free(free_nodes[i]); free_nodes[i] = NULL; }
	}
	free_nodes_index = -1;
    for(i=0; i<MAX_ROI; i++) { roi_node_lookup[i] = NULL; }
	head = NULL;
	tail = NULL;
}


// This API takes the roi_id as the parameter
// The update happens in O(1) time
void roi_updater_update_roi( int roi_id )
{
	// checking the validity of the input parameter
	if((roi_id < MIN_ROI_VALUE) || (roi_id > MAX_ROI_VALUE))
	{
		printf( "Error: Invalid ROI id\n" );
		return;
	}
	
	if(roi_node_lookup[roi_id]) /* roi_id is in the doubly linked list */
	{
		roi_node_t *cur = roi_node_lookup[roi_id];
		
		if(cur->prev) { cur->prev->next=cur->next; }
		if(cur->next) { cur->next->prev=cur->prev; }
		if(cur==tail) { tail=tail->prev; if(!tail) {tail=cur;} }
		if(head!=cur) { cur->next = head; head->prev = cur; cur->prev = NULL; head=cur; }
	}
	else /* the roi_id is not in the doubly linked list*/
	{
		if(free_nodes_index < MAX_HOLDING) /* holding depth is not reached */
		{
			roi_node_t *cur = free_nodes[free_nodes_index]; free_nodes_index++;
			if(free_nodes_index==1)
				tail=cur;
			
			cur->roi_id = roi_id;
			roi_node_lookup[roi_id] = cur;
			if(!head) { head=cur; }
			else { cur->next=head; head->prev=cur; cur->prev=NULL; head=cur; }
		}
		else /* holding depth is reached */
		{
			roi_node_t *cur;
			roi_node_lookup[roi_id]=roi_node_lookup[tail->roi_id];
			roi_node_lookup[tail->roi_id] = NULL;
			cur=tail;
			cur->roi_id = roi_id;
			tail = cur->prev;
			tail->next = NULL;
			cur->next=head; head->prev=cur; cur->prev=NULL; head=cur;
		}
	}
}

static void print_roi_list()
{
	roi_node_t *temp = head;
	
	printf( "Head: " ); if(head) { printf("%d\n", head->roi_id); }
	printf( "Tail: " ); if(tail) { printf("%d\n", tail->roi_id); }
	printf( "DLL : " ); while(temp) { printf("%d  ", temp->roi_id);temp=temp->next; }
	printf("\n\n");
}

int main()
{
	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(4); print_roi_list();
	roi_updater_update_roi(5); print_roi_list();
	roi_updater_update_roi(6); print_roi_list();
	roi_updater_update_roi(7); print_roi_list();
	deinit_roi_updater();

	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	deinit_roi_updater();

	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	deinit_roi_updater();

	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(3); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	deinit_roi_updater();
	
	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	deinit_roi_updater();

	init_roi_updater();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(1); print_roi_list();
	roi_updater_update_roi(500); print_roi_list();
	roi_updater_update_roi(2); print_roi_list();
	roi_updater_update_roi(200); print_roi_list();
	roi_updater_update_roi(300); print_roi_list();
	roi_updater_update_roi(400); print_roi_list();
	deinit_roi_updater();

	return 0;
}
