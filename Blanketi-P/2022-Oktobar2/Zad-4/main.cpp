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
	
	graf.insertEdge(1, 2);
	graf.insertEdge(1, 3);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 4);
	graf.insertEdge(4, 2);
	graf.insertEdge(4, 5);
	graf.insertEdge(5, 2);
	graf.insertEdge(4, 6);
	graf.insertEdge(5, 6);

	LinkedNodeInt* a = graf.findNode(1);
	LinkedNodeInt* b = graf.findNode(2);

	LinkedNodeInt* c = graf.findNode(4);
	LinkedNodeInt* d = graf.findNode(6);

	graf.pathExists(a, b, c, d) ? cout << "Postoji put.\n" : cout << "Ne postoji put";
}