// NP problem jbg, nema nesto efikasno resenje, mora dfs iz svakog cvora...
// mada ionako nigde ni ne pise da treba da je efikasno

int GraphAsListsInt::longestSimpleCycle()
{
	int maxLen = 0;

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		setStatusForAllNodes(0);
		dfsHelper(ptr, ptr, 0, maxLen);
		ptr = ptr->next;

	}

	return maxLen;
}

void GraphAsListsInt::dfsHelper(LinkedNodeInt* start, LinkedNodeInt* ptr, int len, int& maxLen)
{
	if (ptr->status == 1) {
		// nadjen ciklus
		if (ptr->node == start->node)
			maxLen = max(len, maxLen);

		return;
	}

	ptr->status = 1;
	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr) {
		dfsHelper(start, pEdge->dest, len + 1, maxLen);
		pEdge = pEdge->link;
	}
}