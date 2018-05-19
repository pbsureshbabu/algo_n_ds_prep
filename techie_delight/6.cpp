#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct edge_
{
	int src, dst, wt;
} edge_t;

typedef struct enode_
{
	int dst;
	int wt;
	struct enode_ *next;
} enode_t;

enode_t *create_node(int dst, int wt)
{
	enode_t *temp = new enode_t;
	temp->dst=dst;
	temp->wt=wt;
	temp->next=NULL;
	return temp;
}

void delete_node( enode_t *enode)
{
	delete enode;
}

class Graph
{
	vector<enode_t *> adjList;
	
public:
	bool is_edge_present( enode_t *enodes, int dst )
	{
		while(enodes)
		{
			if(enodes->dst==dst)
				return true;
			enodes=enodes->next;
		}
		return false;
	}
	Graph( vector<edge_t> const &edges, int nv, bool isdir )
	{
		adjList.resize(nv, NULL);
		for(int i=0; i<edges.size(); i++)
		{
			int src=edges[i].src;
			int dst=edges[i].dst;
			if(src>=nv || dst>=nv || src<0 || dst<0)
				continue;
			int wt=edges[i].wt;
			if(!is_edge_present(adjList[src], dst))
			{
				enode_t *enode = create_node(dst, wt);
				if(enode)
				{
					enode->next=adjList[src];
					adjList[src]=enode;
				}
			}
			if(!isdir && !is_edge_present(adjList[dst], src))
			{
				enode_t *enode = create_node(src, wt);
				if(enode) 
				{
					enode->next=adjList[dst];
					adjList[dst]=enode;
				}
			}
		}
	}

	~Graph()
	{
	}

	void print_graph()
	{
		for(int i=0; i<adjList.size(); i++)
		{
			cout << i << " : ";
			enode_t *enode = adjList[i];
			while(enode)
			{
				cout << enode->dst << "(" << enode->wt << ") ";
				enode=enode->next;
			}
			cout << endl;
		}
	}

	void bfs( int v )
	{
		const int not_seen=1;
		const int seen=2;
		const int done=3;
		vector<int> states(adjList.size(), not_seen);
		queue<int> vq;
		
		if(v>=adjList.size())
			return;
		vq.push(v);
		states[v]=seen;
		while(!vq.empty())
		{
			int curv=vq.front(); vq.pop();
			enode_t *temp=adjList[curv];
			while(temp)
			{
				if(states[temp->dst]==not_seen)
				{
					vq.push(temp->dst);
					states[temp->dst]=seen;
				}
					temp=temp->next;
			}
			states[curv]=done;
			cout << curv << " ";
		}
		cout << endl;
	}
};

int main()
{
	vector<edge_t> edges;
	edges = {{1,2,1}, {1,3,1}, {1,4,1}, {2,5,1}, {2,6,1}, {5,9,1}, {5, 10, 1}, {4,7,1},
			{4,8,1}, {7,11,1}, {7,12,1}};

	Graph g(edges, 14, false);
	//g.print_graph();
	g.bfs(7);
		
	return 0;
}
