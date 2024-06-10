void GraphAsListsInt::connectMaxAndMin()
{
	// Napravi neorjentisan graf
	toUndirected();

	LinkedNodeInt* nodeFromMinComponent = nullptr;
	LinkedNodeInt* nodeFromMaxComponent = nullptr;

	int minNodes = INT_MAX;
	int maxNodes = 0;

	setStatusForAllNodes(1);
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {

		if (ptr->status == 1) {

			// dfsHelper vraca broj cvorova u komponenti
			// na osnovu njega se pamti jedan cvor iz max komponente i min komponente
			int dfsRes = dfsHelper(ptr);

			if (dfsRes > maxNodes) {
				maxNodes = dfsRes;
				nodeFromMaxComponent = ptr;
			}

			if (dfsRes < minNodes) {
				minNodes = dfsRes;
				nodeFromMinComponent = ptr;
			}
		}

		ptr = ptr->next;
	}

	// ako je i min i max komponenta jedna te ista prekini obradu
	// da se ne bi dodala petlja
	if (nodeFromMaxComponent == nodeFromMinComponent || nodeFromMaxComponent == nullptr || nodeFromMinComponent == nullptr)
		return;

	// duplo da ostane neorjentisan
	insertEdge(nodeFromMaxComponent->node, nodeFromMinComponent->node);
	insertEdge(nodeFromMinComponent->node, nodeFromMaxComponent->node);
}

int GraphAsListsInt::dfsHelper(LinkedNodeInt* ptr)
{
	int numOfNodesToReturn = 0;

	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 2;
	stek.push(ptr);

	while (!stek.isEmpty()) {

		ptr = stek.pop();
		ptr->status = 3; // obradjen -> povecaj broj cvorova koji ce da se vrati
		numOfNodesToReturn++;

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 1) {
				pEdge->dest->status = 2;
				stek.push(pEdge->dest);
			}

			pEdge = pEdge->link;
		}

	}

	return numOfNodesToReturn;
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