#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	for (int i = 1; i <= 14; i++)
		graf.insertNode(i);

	graf.insertEdge(1, 3);
	graf.insertEdge(3, 1);

	graf.insertEdge(1, 7);
	graf.insertEdge(7, 1);

	graf.insertEdge(3, 4);
	graf.insertEdge(4, 3);

	graf.insertEdge(7, 6);
	graf.insertEdge(6, 7);

	graf.insertEdge(4, 6);
	graf.insertEdge(6, 4);

	graf.insertEdge(3, 9);
	graf.insertEdge(9, 3);

	graf.insertEdge(9, 10);
	graf.insertEdge(10, 9);

	graf.insertEdge(10, 2);
	graf.insertEdge(2, 10);

	graf.insertEdge(10, 12);
	graf.insertEdge(12, 10);

	graf.insertEdge(12, 13);
	graf.insertEdge(13, 12);

	graf.insertEdge(10, 6);
	graf.insertEdge(6, 10);

	graf.insertEdge(14, 4);
	graf.insertEdge(4, 14);

	graf.insertEdge(6, 8);
	graf.insertEdge(8, 6);

	graf.insertEdge(8, 5);
	graf.insertEdge(5, 8);

	LinkedNodeInt* airport1 = graf.findNode(3);
	LinkedNodeInt* airport2 = graf.findNode(14);
	LinkedNodeInt* airportEnd = graf.findNode(13);

	cout << graf.numOfSameFlights(airport1, airport2, airportEnd) << endl;
}

