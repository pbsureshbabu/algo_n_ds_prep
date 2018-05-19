// #1 - Terminology and representation of graphs

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXV    (20)

typedef struct edge_
{
	int src, dst;
}edges_t;

typedef struct adjNodes_
{
	int dst;
	struct adjNodes_ *next;
} adjNodes_t;

typedef struct graph_
{
	adjNodes_t *adjNodes[MAXV];
} graph_t;

graph_t *create_graph( edges_t *edges, int tot_edges )
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
		if(!(src<MAXV && dst<MAXV))
			continue;
		adjNodes_t *anode = (adjNodes_t *)malloc(sizeof(adjNodes_t));
		anode->dst = dst;
		anode->next = g->adjNodes[src];
		g->adjNodes[src]=anode;
	}
	return g;
}

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
			cout << "(" << i << "," << temp->dst << ") ";
			temp=temp->next;
		}
		cout << endl;
	}
}

int main()
{
	edges_t edges[] = {{0,1}, {1,2}, {2,0}, {2,1}, {3,2}, {4,5}, {5,4}};
	int tot_edges=sizeof(edges)/sizeof(edges[0]);

	graph_t *g=create_graph( edges, tot_edges );
	if(!g)
		return 0;
	print_graph(g);
	delete_graph(g);
	
	return 0;
}
