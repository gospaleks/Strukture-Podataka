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
}