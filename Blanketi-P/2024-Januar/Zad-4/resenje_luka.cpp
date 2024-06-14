bool GraphAsListsInt::ArePathsPossible(LinkedNodeInt* start, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid)
{
	setStatusForAllNodes(0);
	if (NajkraciPutOdADoB(start, mid) > -1)
	{
		bool put1=false, put2 = false;
		setStatusForAllNodes(0);
		start->status = 1;
		if (NajkraciPutOdADoB(mid, goal1) > -1)
		{
			put1 = true;
			setStatusForAllNodes(0);

		}
		if (put1 && NajkraciPutOdADoB(mid, goal2) > -1)
			put2 = true;
		if (put1 && put2)
			return true;
	}
	return false;

}

int GraphAsListsInt::NajkraciPutOdADoB(LinkedNodeInt* A, LinkedNodeInt* B)
{
	int min = INT_MAX;
	if (A == NULL || B == NULL)
		return -1;
	//setStatusForAllNodes(0);
	pomocna(A, B, min, 0);
	return min == INT_MAX ? -1 : min;
}

void GraphAsListsInt::pomocna(LinkedNodeInt* trenutni, LinkedNodeInt* kraj, int& m, int trbroj)
{
	if (trenutni==kraj)//status kraja nije 1
	{
		m = min(trbroj, m);
		return ;
	}
	if (trenutni->status == 1)
		return;
	trenutni->status = 1;
	LinkedEdgeInt* edge = trenutni->adj;
	while (edge != NULL)
	{
		pomocna(edge->dest, kraj, m, trbroj + 1);
		edge = edge->link;
	}
}

void main() 
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
	graf.insertNode(10);
	graf.insertEdge(1,2);
	graf.insertEdge(2, 1);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 2);
	graf.insertEdge(3, 4);
	graf.insertEdge(4, 3);
	graf.insertEdge(4, 5);
	graf.insertEdge(5, 4);
	graf.insertEdge(5,6);
	graf.insertEdge(6, 5);
	graf.insertEdge(6, 7);
	graf.insertEdge(7, 6);
	graf.insertEdge(6, 8);
	graf.insertEdge(8, 6);
	graf.insertEdge(8, 9);
	graf.insertEdge(9, 8);
	graf.insertEdge(1, 4);
	graf.insertEdge(4, 1);
	cout << graf.ArePathsPossible(graf.findNode(6), graf.findNode(5), graf.findNode(1), graf.findNode(7))<<endl;
	cout << graf.ArePathsPossible(graf.findNode(7), graf.findNode(5), graf.findNode(1), graf.findNode(4)) << endl;
	cout << graf.ArePathsPossible(graf.findNode(6), graf.findNode(2), graf.findNode(1), graf.findNode(9));
}