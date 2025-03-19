#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V;
	//Array of list
	list<int> *l;

public:
	//Constructs graph with int v
	Graph(int V)
	{
		this->V = V;
		//the int l is the same number as the numer of list
		l = new list<int>[V];
	}

	//adds edges to the graph
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x); 
	}

	//prints the graph
	void printAdjList() {
		//loops the vertex number
		for(int i = 0; i < V; i++) {
			cout << "Vertex " << i << "->";
			for (int nbr : l[i]) {
				//loops the graph numbers
				cout << nbr << " , ";
			}
			cout << endl;
		}
	}
};

int main()
{
	//adds the edges for the graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);

	//prints the graph
	g.printAdjList();

	return 0;
}