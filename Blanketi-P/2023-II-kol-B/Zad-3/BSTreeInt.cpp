BSTNodeInt* BSTreeInt::getMaxDifferenceNode()
{
	// vraca cvor kod koga je najveca razlika izmedju sume parnih i neparnih cvorova u njegovim podstablima

	BSTNodeInt* maxNode = nullptr;
	int maxDiff = 0, sumParni = 0, sumNeparni = 0;
	getMaxDifferenceNode(root, &maxNode, maxDiff, sumParni, sumNeparni);
	return maxNode;
}

void BSTreeInt::getMaxDifferenceNode(BSTNodeInt* root, BSTNodeInt** maxNode, int& maxDiff, int& sumParni, int& sumNeparni)
{
	if (root == nullptr) {
		return;
	}

	// ako je list
	if (root->left == nullptr && root->right == nullptr) {
		if (root->getKey() % 2 == 0)
			sumParni += root->getKey();
		else
			sumNeparni += root->getKey();
		return;
	}

	// inace izracunaj za levo i desno podstablo
	int sumParniLeft = 0, sumNeparniLeft = 0;
	int sumParniRight = 0, sumNeparniRight = 0;

	getMaxDifferenceNode(root->left, maxNode, maxDiff, sumParniLeft, sumNeparniLeft);
	getMaxDifferenceNode(root->right, maxNode, maxDiff, sumParniRight, sumNeparniRight);

	sumParni = sumParniLeft + sumParniRight;
	sumNeparni = sumNeparniLeft + sumNeparniRight;
	int razlika = abs(sumParni - sumNeparni);
	// ako je razlika veca od trenutne max razlike
	if (razlika > maxDiff) {
		maxDiff = razlika;
		*maxNode = root;
	}

	// cout << root->getKey() << ", diff: " << razlika << endl;

	// dodaj trenutni cvor na sumu
	if (root->getKey() % 2 == 0)
		sumParni += root->getKey();
	else
		sumNeparni += root->getKey();
}
