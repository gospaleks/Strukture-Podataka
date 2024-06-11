int GraphAsListsInt::getMaxConnectionsDisjointSubgraph()
{
	toUndirected(); // pise da se podrazumeva al to je na papir, ovako mora f-ja ili da se rucno uvek dodaju grane duplo
	setStatusForAllNodes(1);	// 1 - neobradjeni

	int maxEdges = 0;

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		// pokreni pretragu na neobradjenim cvorovima
		// jedna pretraga vraca broj grana u jednoj komponenti (tj disjunktnom podgrafu)
		if (ptr->status == 1)
			maxEdges = max(maxEdges, bfsHelper(ptr));

		ptr = ptr->next;
	}

	return maxEdges;
}

int GraphAsListsInt::bfsHelper(LinkedNodeInt* ptr)
{
	int numOfEdges = 0;

	QueueAsArrayLinkedNodeInt que(nodeNum);
	ptr->status = 2; // 2 - ubacen u red
	que.enqueue(ptr);

	while (!que.isEmpty()) {
		ptr = que.dequeue();
		ptr->status = 3; // 3 - obradjen

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 1) {
				pEdge->dest->status = 2;
				que.enqueue(pEdge->dest);
			}

			++numOfEdges;
			pEdge = pEdge->link;
		}
	}

	// podeljeno sa 2 jer u principu bfs mi vrati 2*m
	// jer za svakog suseda ja uracunam granu pa u sustini uvek duplo uracunam
	return numOfEdges / 2;
}

// may the force be with you !!! sigurno moze pametnije?
void GraphAsListsInt::toUndirected()
{
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			LinkedEdgeInt* tmp = pEdge->dest->adj;
			while (tmp != nullptr && tmp->dest->node != ptr->node)
				tmp = tmp->link;

			if (tmp == nullptr) {
				pEdge->dest->adj = new LinkedEdgeInt(ptr, pEdge->dest->adj);
			}

			pEdge = pEdge->link;
		}

		ptr = ptr->next;
	}
}