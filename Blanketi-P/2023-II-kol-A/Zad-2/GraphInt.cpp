int GraphAsListsInt::subgraphCnt(int p)
{
	toUndirected();

	setStatusForAllNodes(1); // neobradjeni

	int rez = 0;
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {

		if (ptr->status == 1) {
			if (dfsHelper(ptr, p))
				rez++;
		}

		ptr = ptr->next;
	}

	return rez;
}

bool GraphAsListsInt::dfsHelper(LinkedNodeInt* ptr, int p)
{
	bool ima = false;
	
	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 2; // u strukturi steka
	stek.push(ptr);

	while (!stek.isEmpty()) {
		
		ptr = stek.pop();

		if (ptr->node > p)
			ima = true;

		ptr->status = 3; // obradjen

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			
			if (pEdge->dest->status == 1) {
				pEdge->dest->status = 2; // u strukturi steka
				stek.push(pEdge->dest);
			}

			pEdge = pEdge->link;
		}
	}

	return ima;
}

void GraphAsListsInt::toUndirected()
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			LinkedEdgeInt* tmp = pEdge->dest->adj;

			// proveri dal vec ima povratna grana
			while (tmp != nullptr && tmp->dest->node != ptr->node) {
				tmp = tmp->link;
			}

			// ako je ispao znaci da nema povratna grana i treba je dodati
			if (tmp == nullptr) {
				pEdge->dest->adj = new LinkedEdgeInt(ptr, pEdge->dest->adj);
			}

			pEdge = pEdge->link;
		}

		ptr = ptr->next;
	}
}