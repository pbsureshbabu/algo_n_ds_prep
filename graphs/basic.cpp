#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXV    (25)

// struct holding information of a particular edge going out from a vertex
typedef struct enode_
{
	int y;
	int weight;
	struct enode_ *n;
} enode_t;

// struct of the graph
typedef struct graph_
{
	int nvertices;
	int nedges;
	bool isdirected;
	int degree[MAXV];
	enode_t *enodes[MAXV];
} graph_t;

void init_graph( graph_t *g, bool isdirected )
{
	g->nvertices = 0;
	g->nedges = 0;
	g->isdirected = isdirected;
	for(int i=0; i<MAXV; i++)
	{
		g->degree[i] = 0;
		g->enodes[i] = NULL;
	}
}

void print_graph( graph_t *g )
{
	cout << "nvertices: " << g->nvertices << endl;
	cout << "nedges: " << g->nedges << endl;
	cout << "isdirected: " << g->isdirected << endl;
	cout << endl;
	for(int i=0; i<g->nvertices; i++)
	{
		cout << "Vertex " << i <<" info: " << endl;
		cout << "    degree: " << g->degree[i] << endl;
		cout << "    edge list: ";
		enode_t *p = g->enodes[i];
		while(p)
		{
			cout << "(" << p->y <<", " << p->weight << "), ";
			p=p->n;
		}
		cout << endl;
	}
}
void insert_edge( graph_t *g, int x, int y, int w, bool isdirected )
{
	enode_t *p = (enode_t *)malloc(sizeof(enode_t));
	p->y = y;
	p->weight = w;
	p->n = g->enodes[x];
	g->enodes[x] = p;
	g->degree[x]++;

	if(!isdirected)
		insert_edge( g, y, x, w, true );
}

void read_graph( graph_t *g, bool isdirected )
{
	int n;
	cin >> g->nvertices;
	cin >> g->nedges;
	g->isdirected = isdirected;
	for(int i=0; i<g->nedges; i++)
	{
		int x, y;
		cin >> x >> y;
		insert_edge( g, x, y, 0, isdirected );
	}
}

int main()
{
	graph_t g;

	init_graph( &g, false );
	read_graph( &g, false );
	print_graph( &g );
	
	return 0;
}
