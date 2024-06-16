/*
	ovo je malo bolje resenje od onog dole
	ide se po nivoima i cvorove na svakom nivou obelezim sa 0, pa sa 1, pa sa 2... itd
 	pretraga se prekida kad dodjem do nivoa n, posle samo prebrojim koliko cvora ima sa statusom n
*/

int GraphAsListsInt::reachableInNHoops(LinkedNodeInt* a, int n)
{
	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = a;
	
	QueueAsArrayLinkedNodeInt red(nodeNum);
	ptr->status = 0;
	red.enqueue(ptr);

	while (!red.isEmpty()) {
		ptr = red.dequeue();
		LinkedEdgeInt* pEdge = ptr->adj;

		if (ptr->status == n) {
			break;
		}

		while (pEdge != nullptr) {

			pEdge->dest->status = ptr->status + 1;
			red.enqueue(pEdge->dest);
			
			pEdge = pEdge->link;
		}
	}


	int retVal = 0;
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == n)
			++retVal; // cak ovde moze i ispis da se vide koji su to cvorovi
		ptr = ptr->next;
	}
	
	return retVal;
}

/*
int GraphAsListsInt::reachableInNHoops(LinkedNodeInt* a, int n)
{
	LinkedNodeInt* ptr = a;

	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(ptr);
	int brDodatih = 1;
	int brNivoa = 0;

	while (!red.isEmpty()) {

		if (brDodatih == red.numberOfElements()) {
			if (brNivoa == n) {

				// Ako je broj nivoa jednak n, onda izbroj koliko razlicitih cvorova imas u redu i to je resenje
				// std::set -> u set kad se doda ne dodaju se duplikati pa je zgodan za ovakvu situaciju
				// ili aip-ovski s 2 for petlje ko debil!
				std::set<int> skup;
				while (!red.isEmpty())
					skup.insert(red.dequeue()->node);

				return skup.size();
			}

			++brNivoa;
			brDodatih = 0;
		}

		ptr = red.dequeue();

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			red.enqueue(pEdge->dest);
			++brDodatih;

			pEdge = pEdge->link;
		}

	}

	return 0;
}*/
