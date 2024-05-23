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

	graf.insertEdge(1, 2);
	graf.insertEdge(1, 6);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 4);
	graf.insertEdge(6, 4);
	graf.insertEdge(6, 5);
	graf.insertEdge(5, 1);
	graf.insertEdge(7, 4);
	graf.insertEdge(4, 5);

	graf.pathWithMinimalNumberOfEdges(1, 4) ? cout << "nadjen put\n" : cout << "nije nadjen put\n";
}

