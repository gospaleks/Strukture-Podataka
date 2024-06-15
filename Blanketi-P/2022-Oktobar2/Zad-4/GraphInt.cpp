bool GraphAsListsInt::pathExists(LinkedNodeInt* a, LinkedNodeInt* b, LinkedNodeInt* c, LinkedNodeInt* d)
{
	// podrazumevam da ce da se unese ispravna grana, tj da ce da postoji poteg c-d
	// moze da se prodje kroz listu potega cvora c i da se ispita da li postoji dest da je d
	return (dfsHelper(a, c) && dfsHelper(d, b));
}

bool GraphAsListsInt::dfsHelper(LinkedNodeInt* ptrStart, LinkedNodeInt* ptrEnd)
{
	setStatusForAllNodes(1); // 1 - neobradjen

	LinkedNodeInt* ptr = ptrStart;
	ptr->status = 2; // 2 - na steku

	StackAsArrayLinkedNodeInt stek(nodeNum);
	stek.push(ptr);

	while (!stek.isEmpty()) {

		ptr = stek.pop();
		ptr->status = 3; // 3 - obradjen

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
				
			// nadjen put
			if (pEdge->dest == ptrEnd)
				return true;

			if (pEdge->dest->status == 1) {
				pEdge->dest->status = 2;
				stek.push(pEdge->dest);
			}

			pEdge = pEdge->link;
		}
	}

	return false;
}