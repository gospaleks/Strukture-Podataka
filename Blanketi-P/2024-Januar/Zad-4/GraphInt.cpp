bool GraphAsListsInt::arePathsPossible(LinkedNodeInt* sstart, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid)
{
	LinkedNodeInt* ptr = this->start;
	while (ptr != nullptr) {
		ptr->status = 1;
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	// 1. korak: pomocu BFS-a nalazenje najkraceg puta od start do mid
	if (!isTherePathBetween(sstart, mid))
		return false;

	// 2. korak
	// Kada je nadjen put do mid, sve cvorove postavljamo na status 1 osim cvorova na putu izmedju start i mid
	// jer njih ne zelimo da koristimo u trazenju puta od mid do goal1 i goal2
	setStatusForAllNodes(1);
	ptr = mid;
	while (ptr != nullptr) {
		ptr->status = 3;
		ptr = ptr->prev;
	}

	// 3. korak: nalazenje puta od mid do goal1 i goal2
	if (!isTherePathBetween(mid, goal1))
		return false;

	// resetovanje statusa da ne bi proso preko neki cvor koji je predjen od start do mid
	// reset se radi jer put od mid do goal2 ne zavisi od puta izmedju mid i goal1
	setStatusForAllNodes(1);
	ptr = mid;
	while (ptr != nullptr) {
		ptr->status = 3;
		ptr = ptr->prev;
	}

	// 4. korak: provera da li postoji put od mid do goal2
	if (!isTherePathBetween(mid, goal2))
		return false;

	// ako je sve proslo, ispisi puteve (msm da ne mora al eto) i vrati true
	cout << "Start -> Mid -> Goal1: ";
	ptr = goal1;
	while (ptr != nullptr) {
		cout << ptr->node << " ";
		ptr = ptr->prev;
	}

	cout << endl << "Start -> Mid -> Goal2: ";
	ptr = goal2;
	while (ptr != nullptr) {
		cout << ptr->node << " ";
		ptr = ptr->prev;
	}

	cout << endl;

	return true;
}

/* Obican BFS s tim da prekida pretragu kad nadje ptrEnd */
bool GraphAsListsInt::isTherePathBetween(LinkedNodeInt* ptr, LinkedNodeInt* ptrEnd)
{
	ptr->status = 2;
	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(ptr);

	while (!red.isEmpty()) {
		ptr = red.dequeue();
		ptr->status = 3;

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			// nadjen put
			if (pEdge->dest == ptrEnd) {
				pEdge->dest->prev = ptr;
				return true;
			}
			else if (pEdge->dest->status == 1) {
				pEdge->dest->status = 2;
				pEdge->dest->prev = ptr;
				red.enqueue(pEdge->dest);
			}

			pEdge = pEdge->link;
		}
	}

	return false;
}