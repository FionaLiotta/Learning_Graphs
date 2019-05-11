#include <iostream>
#include <vector>
#include <limits>

const int MAXV = 100;

struct edgenode {
	int y;
	int weight;
	edgenode *next;
};

struct graph {
	std::vector<edgenode*> edges;
	bool directed;
	int numVerts;
};

void insert_edge(graph &g, int x, int y, int weight, bool directed);
void print_graph(graph &g);
void prims(graph &g, int start);
void kruskals(graph &g);

int main() {
	graph g;
	insert_edge(g, 1, 2, 5, false);
	insert_edge(g, 1, 3, 9, false);
	insert_edge(g, 1, 4, 7, false);
	insert_edge(g, 2, 3, 7, false);
	insert_edge(g, 2, 5, 12, false);
	insert_edge(g, 3, 5, 4, false);
	insert_edge(g, 3, 6, 3, false);
	insert_edge(g, 4, 3, 4, false);
	insert_edge(g, 4, 6, 2, false);
	insert_edge(g, 4, 7, 5, false);
	insert_edge(g, 5, 6, 7, false);
	insert_edge(g, 6, 7, 2, false);
	print_graph(g);
	prims(g, 1);
	system("pause");
	return 0;
}

void insert_edge(graph &g, int x, int y, int weight, bool directed) {
	while (x >= g.edges.size()) {
		g.edges.push_back(NULL);
		g.numVerts++;
	}
	edgenode *p = new edgenode;
	p->y = y;
	p->weight = weight;
	p->next = g.edges[x];
	g.edges[x] = p;
	if (!directed) {
		insert_edge(g, y, x, weight, true);
	}
}

void print_graph(graph &g) {
	edgenode *p;
	for (int i = 1; i < g.edges.size(); i++) {
		if (g.edges[i] != NULL) {
			p = g.edges[i];
			std::cout << i << " connects to ";
			while (p != NULL) {
				std::cout << p->y << " ";
				p = p->next;
			}
			std::cout << "\n";
		}
	}
}

void prims(graph &g, int start) {
	bool intree[MAXV];
	int distance[MAXV];
	int parent[MAXV];
	int current, candidate, dist;
	
	edgenode *p;
	for (int i = 0; i < MAXV; i++) {
		intree[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}

	current = start;
	while (intree[current] == false) {
		intree[current] = true;
		p = g.edges[current];
		while (p != NULL) {
			candidate = p->y;
			if (p->weight < distance[candidate] && intree[candidate] == false) {
				distance[candidate] = p->weight;
				parent[candidate] = current;
			}
			p = p->next;
		}

		current = 1;
		dist = INT_MAX;
		for (int i = 1; i < g.edges.size(); i++) {
			if (distance[i] < dist && intree[i] == false) {
				current = i;
				dist = distance[i];
			}
		}
	}
	for (int i = 0; i < g.edges.size(); i++) {
		std::cout << i << " parent: " << parent[i] << "\n";
	}

}
	void kruskals(graph &g) {
	}