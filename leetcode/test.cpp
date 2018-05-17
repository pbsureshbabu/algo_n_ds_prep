#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXV    (50)

typedef struct enode_
{
	int y;
	int w;
	struct enode_ *n;
} enode_t;

typedef struct graph_
{
	int nv;
	int ne;
	bool is_directed;
	int outdeg[MAXV];
	enode_t *enodes[MAXV];
} graph_t;

void add_edge( graph_t *g, int src, int dst, int wt )
{
	if(src>=g->nv || dst>=g->nv)
	{
		cout << "invalid edge" << endl;
		return;
	}
	enode_t *tenode = (enode_t *)malloc(sizeof(enode_t));
	tenode->y=dst;
	tenode->w=wt;
	tenode->n=g->enodes[src];
	g->enodes[src]=tenode;
	g->outdeg[src]++;
	g->ne++;
}

void add_vertex( graph_t *g )
{
	if(g->nv+1<MAXV)
		g->nv++;
}

void init_graph( graph_t *g, bool is_directed )
{
	g->nv=0;
	g->ne=0;
	g->is_directed = is_directed;
	for(int i=0; i<MAXV; i++)
	{
		g->outdeg[i]=0;
		g->enodes[i]=NULL;
	}
}

void print_graph( graph_t *g )
{
	cout << "no of vertices = " << g->nv << endl;
	cout << "no of edges = " << g->ne << endl;
	cout << "is directed = " << g->is_directed << endl;
	for(int i=0; i<g->nv; i++)
	{
		cout << "info for vertex " << i << " : " << endl;
		cout << "outdeg = " << g->outdeg[i] << endl;
		enode_t *t = g->enodes[i];
		while(t) { cout << t->y;t=t->n;}
		cout << endl;
	}
}

int main()
{
	graph_t g;

	init_graph( &g, true );
	add_vertex( &g );
	add_vertex( &g );
	add_vertex( &g );
	add_vertex( &g );
	add_vertex( &g );
	add_edge( &g, 0, 1, 1);
	
	
	print_graph( &g );
	
	return 0;
}


