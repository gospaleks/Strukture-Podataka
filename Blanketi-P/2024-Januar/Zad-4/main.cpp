#include <iostream>
using namespace std;

#include "GraphInt.h"

/* 
	Za razumevanje najbolje nacrtati graf iz main-a (usmeren je)
*/


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

	graf.insertEdge(3, 5);
	graf.insertEdge(3, 4);
	graf.insertEdge(4, 5);
	graf.insertEdge(5, 1);
	graf.insertEdge(4, 2);
	graf.insertEdge(1, 2);
	graf.insertEdge(2, 6);
	graf.insertEdge(6, 7);
	graf.insertEdge(7, 2);
	graf.insertEdge(6, 8);

	LinkedNodeInt* sstart = graf.findNode(3);
	LinkedNodeInt* goal1 = graf.findNode(8);
	LinkedNodeInt* goal2 = graf.findNode(7);
	LinkedNodeInt* mid = graf.findNode(2);

	graf.arePathsPossible(sstart, goal1, goal2, mid) ? cout << "Moguce je" : cout << "Nije moguce";
}