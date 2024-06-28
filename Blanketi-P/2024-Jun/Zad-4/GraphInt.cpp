int GraphAsListsInt::printMaxConnectedComponentNodes()
{
	toUndirected();

	LinkedNodeInt* ptr = start;
	setStatusForAllNodes(1);		// 1 neobradjen, 2 u strukturu, 3 obradjen
	int maxBr = 0;
	LinkedNodeInt* maxPtr = start;
	while (ptr != nullptr)
	{
		if (ptr->status == 1)
		{
			int tmp = bfs(ptr, 0);
			if (tmp > maxBr)
			{
				maxBr = tmp;
				maxPtr = ptr;
			}
		}
		ptr = ptr->next;
	}

	setStatusForAllNodes(1);
	bfs(maxPtr, 1);


	return 0;
}

int GraphAsListsInt::bfs(LinkedNodeInt* p, bool ind)
{
	int rez = 0;
	QueueAsArrayLinkedNodeInt red(nodeNum);

	red.enqueue(p);
	p->status = 2;
	while (!red.isEmpty())
	{
		p = red.dequeue();
		if (ind == true)
		{
			cout << p->node << " ";
		}
		p->status = 3;
		rez++;
		LinkedEdgeInt* pEdge = p->adj;
		while (pEdge != nullptr)
		{
			if (pEdge->dest->status == 1)
			{
				red.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}

	return rez;
}

void GraphAsListsInt::toUndirected()
{
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdge = ptr->adj;

		while (pEdge != nullptr)
		{
			LinkedEdgeInt* dst = pEdge->dest->adj;

			while (dst != nullptr && dst->dest != ptr)
				dst = dst->link;

			if (dst == nullptr)
				pEdge->dest->adj = new LinkedEdgeInt(ptr, pEdge->dest->adj);

			pEdge = pEdge->link;

		}

		ptr = ptr->next;
	}
}
