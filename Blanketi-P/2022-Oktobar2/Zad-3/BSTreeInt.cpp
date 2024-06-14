BSTNodeInt* BSTreeInt::findSibling(BSTNodeInt* p)
{
	// Ako je cvor p koren, onda nema brata
	if (root == p)
		return nullptr;

	BSTNodeInt* ptr = root;

	// Idemo po nivoima preko BFS-a
	QueueAsArrayBSTNodeInt red(numOfElements);
	red.enqueue(ptr);
	int brDod = 1;

	bool uRed = false;

	while (!red.isEmpty()) {

		// Kada udje u if to znaci da su u redu svi elementi istog nivoa
		if (brDod == red.numberOfElements()) {

			// Ako se p nalazi u redu, pitamo da l u redu ima jos elemenata‚ i nadji prvi koji nije p
			if (uRed && red.numberOfElements() > 1) {
				do {
					ptr = red.dequeue();
					if (ptr != p)
						return ptr;
				} while (!red.isEmpty());
			}
			else if (uRed)	// Ako je p sam u nivou, onda nema brata
				return nullptr;

			brDod = 0;		// Resetujemo brojac dodatih elemenata jer se tako on poklopi sa brojem elemenata jedino ako je njegov broj jedank broju elemenata reda
		}

		ptr = red.dequeue();

		if (ptr->left != nullptr)
		{
			if (ptr->left == p)
				uRed = true;

			red.enqueue(ptr->left);
			++brDod;
		}

		if (ptr->right != nullptr)
		{
			if (ptr->right== p)
				uRed = true;

			red.enqueue(ptr->right);
			++brDod;
		}
	}

	return nullptr;
}