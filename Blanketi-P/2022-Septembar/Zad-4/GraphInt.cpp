int GraphAsListsInt::numOfSameFlights(LinkedNodeInt* airport1, LinkedNodeInt* airport2, LinkedNodeInt* airportEnd)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	bfsHelper(airport1, airportEnd);

	// resetuj sve statuse
	setStatusForAllNodes(0);

	// vrati se po putanji prvog i stavi status na 10 (npr)
	ptr = airportEnd;
	while (ptr != nullptr) {
		ptr->status = 10;
		ptr = ptr->prev;
	}

	// resetuj prev pointer-e
	ptr = start;
	while (ptr != nullptr) {
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	bfsHelper(airport2, airportEnd);

	// prebroj koliko 11-ki ima po putanji airport2 -> airportEnd
	ptr = airportEnd;
	int brZajGrana = 0;
	while (ptr != nullptr) {
		if (ptr->status == 11)
			++brZajGrana;
		ptr = ptr->prev;
	}

	--brZajGrana; // -1 zato sto smo izbrojali cvorove a trebaju nam grane

	return brZajGrana;
}

void GraphAsListsInt::bfsHelper(LinkedNodeInt* ptr, LinkedNodeInt* ptrEnd)
{
	QueueAsArrayLinkedNodeInt red(nodeNum);

	// spec slucaj ako se putevi preklapaju
	if (ptr->status == 10)
		ptr->status = 11;

	red.enqueue(ptr);

	while (!red.isEmpty()) {

		ptr = red.dequeue();

		if (ptr->status != 11)
			ptr->status = 1;

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 0 || pEdge->dest->status == 10) {
				pEdge->dest->prev = ptr;

				if (pEdge->dest->status == 10)
					pEdge->dest->status = 11; // 11 znaci da je zajednicki cvor (posle samo izbrojimo klk ima 11-ke)

				red.enqueue(pEdge->dest);
			}

			if (pEdge->dest == ptrEnd) {
				pEdge->dest->prev = ptr;
				return;
			}

			pEdge = pEdge->link;
		}
	}
}
