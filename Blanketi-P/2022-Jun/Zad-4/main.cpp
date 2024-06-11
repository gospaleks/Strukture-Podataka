#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[])
{
	GraphAsListsInt graf;

	graf.insertNode(1);
	graf.insertNode(2);
	graf.insertNode(3);
	graf.insertNode(4);
	graf.insertNode(5);
	graf.insertNode(6);
	graf.insertNode(7);
	graf.insertNode(8);
	graf.insertNode(9);

	graf.insertEdge(5, 2);
	graf.insertEdge(5, 4);
	graf.insertEdge(2, 3);
	graf.insertEdge(2, 4);

	graf.insertEdge(1, 6);
	graf.insertEdge(1, 7);
	graf.insertEdge(6, 7);

	// graf.insertEdge(6, 8);

	graf.insertEdge(8, 9);

	cout << graf.getMaxConnectionsDisjointSubgraph() << endl;
}