// #1 - Terminology and representation of graphs

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXV    (20)

// this is for just passing the data to the graph creation
typedef struct edge_
{
	int src, dst, wt;
}edges_t;

// adjacency list node
typedef struct adjNodes_
{
	int dst;
	int wt;
	struct adjNodes_ *next;
} adjNodes_t;

// graph struct
typedef struct graph_
{
	adjNodes_t *adjNodes[MAXV];
} graph_t;

// check whether the edge is already in the adjacency list
bool is_in_the_list( graph_t *g, int src, int dst )
{
	if(src>=MAXV || dst>=MAXV)
		return true;
	adjNodes_t *temp;
	temp=g->adjNodes[src];
	while(temp)
	{
		if(temp->dst==dst)
			return true;
		temp=temp->next;
	}
	return false;
}

// create a graph
graph_t *create_graph( edges_t *edges, int tot_edges, bool is_directed )
{
	graph_t *g;
	g = (graph_t *)malloc(sizeof(graph_t));
	if(!g)
		return NULL;
	for(int i=0; i<MAXV; i++)
		g->adjNodes[i]=NULL;
	for(int i=0; i<tot_edges; i++)
	{
		int src=edges[i].src;
		int dst=edges[i].dst;
		int wt=edges[i].wt;
		if(!(src<MAXV && dst<MAXV))
			continue;
		
		// creating the edge from source to destination
		if(!is_in_the_list(g, src, dst))
		{
			adjNodes_t *anode = (adjNodes_t *)malloc(sizeof(adjNodes_t));
			anode->dst = dst;
			anode->wt = wt;
			anode->next = g->adjNodes[src];
			g->adjNodes[src]=anode;
		}

		if(!is_directed)
		{
			// also create the edge from dest to src
			// it would be nice to check, if for that particular dst, where there is a particular src
			if(!is_in_the_list(g, dst, src))
			{
				adjNodes_t *anode = (adjNodes_t *)malloc(sizeof(adjNodes_t));
				anode->dst = src;
				anode->wt = wt;
				anode->next = g->adjNodes[dst];
				g->adjNodes[dst]=anode;
			}
		}
	}
	return g;
}

// delete the graph
void delete_graph( graph_t *g)
{
	if(!g)
		return;
	for(int i=0; i<MAXV; i++)
	{
		adjNodes_t *temp;
		temp=g->adjNodes[i];
		while(temp)
		{
			adjNodes_t *delNode;
			delNode = temp;
			temp=temp->next;
			free(delNode);
		}
	}
	free(g);
}

// print the graph
void print_graph( graph_t *g )
{
	for(int i=0; i<MAXV; i++)
	{
		adjNodes_t *temp;
		temp=g->adjNodes[i];
		if(!temp)
			continue;
		while(temp)
		{
			cout << "[" << i << "," << temp->dst << "(" << temp->wt << ")]  " ;
			temp=temp->next;
		}
		cout << endl;
	}
}

int main()
{
	edges_t edges[] = {{0,1,6}, {1,2,7}, {2,0,5}, {2,1,4}, {3,2,10}, {4,5,1}, {5,4,3}};
	int tot_edges=sizeof(edges)/sizeof(edges[0]);

	graph_t *g=create_graph( edges, tot_edges, true );
	if(!g)
		return 0;
	print_graph(g);
	delete_graph(g);
	
	return 0;
}
