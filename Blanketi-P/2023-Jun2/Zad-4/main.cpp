#include <iostream>
using namespace std;

#include "GraphInt.h"

/* ovaj primer je dobar je ima ciklus ali i cvorove ciji je ulazni stepen 0 
	lepo se moze proveriti kako radi
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


	graf.insertEdge(1, 2);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 1);
	graf.insertEdge(4, 2);
	graf.insertEdge(4, 5);
	graf.insertEdge(6, 5);
	graf.insertEdge(7, 6);

	graf.isCyclic() ? cout << "ima ciklus\n" : cout << "nema ciklus\n";
}
