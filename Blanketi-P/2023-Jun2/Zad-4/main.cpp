#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[])
{
	GraphAsListsInt graf;

	graf.insertNode(2);
	graf.insertNode(1);
	graf.insertNode(4);
	graf.insertNode(3);
	graf.insertNode(5);

	graf.insertEdge(1, 2);
	graf.insertEdge(2, 4);
	graf.insertEdge(4, 3);
	graf.insertEdge(3, 5);
	graf.insertEdge(2, 3);
	// graf.insertEdge(5, 2);

	graf.isCyclic() ? cout << "ima ciklus\n" : cout << "nema ciklus\n";
}