
bool GraphAsListsInt::isCyclic()
{
	LinkedNodeInt* ptr = start;

	setStatusForAllNodes(0);

	int currentStatus = 10;
	while (ptr != nullptr) {
		if (ptr->status == 0) {
			if (dfsRec(ptr, currentStatus++))
				return true;
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::dfsRec(LinkedNodeInt* ptr, int currentStatus)
{
	ptr->status = currentStatus; // obradjeni
	LinkedEdgeInt* pEdge = ptr->adj;

	while (pEdge != nullptr) {

		if (pEdge->dest->status == currentStatus)
			return true;
		else if (pEdge->dest->status == 0)
			return dfsRec(pEdge->dest, currentStatus);

		pEdge = pEdge->link;
	}
}


/*
	Aleksino resenje (neka vrsta topoloskog obilaska)
 	pokrece se obilazak iz cvorova ciji je ulazni stepen 0 (jer oni ne mogu da se obidju nikako drugacije)
*/

/*
bool GraphAsListsInt::isCyclic()
{
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {
		ptr->status = -1; // ulazni stepen 0
		ptr = ptr->next;
	}
	
	ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr)
		{
			if (pEdge->dest->status == -1)
				pEdge->dest->status = 0; // znaci da je ulazni stepen veci od 0 
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}

	ptr = start;
	bool uslo = 0;
	while (ptr != nullptr)
	{
		if (ptr->status == -1)
		{
			uslo = 1;
			postaviSveOsimSaUlaznimStepenom0(0);
			if (dfsRec(ptr))
			{
				return true;
			}
		}
		ptr = ptr->next;
	}
	if (!uslo)
		return true;
	return false;
}

*/
