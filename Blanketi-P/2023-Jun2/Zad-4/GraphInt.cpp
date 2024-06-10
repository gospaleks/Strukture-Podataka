/*
	Posto kaze da ne podrazumevamo da je ista implementirano 
	radio sam DFS reukruzivno da ne bi koristio ni StackAsArrayInt klasu
*/
bool GraphAsListsInt::isCyclic()
{
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {
		ptr->status = 0; // neobradjeni
		ptr = ptr->next;
	}

	ptr = start;

	return dfsRec(ptr);
}

bool GraphAsListsInt::dfsRec(LinkedNodeInt* ptr)
{
	bool res = false;

	// cim naidje na neki koji je vec obradjen znaci da je pronadjen ciklus -> dalja obrada nije potrebna
	if (ptr->status == 1)
		res = true;

	else {
		ptr->status = 1; // obradjeni
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			res = dfsRec(pEdge->dest);
			pEdge = pEdge->link;
		}
	}

	return res;
}