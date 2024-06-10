BSTNodeInt* BSTreeInt::maxHeightDiff()
{
	// cisto da ne puca kad je prazno stablo
	if (root == nullptr)
		return new BSTNodeInt(-1);

	// ako je samo jedan cvor u stablu vrati njega
	if (root->left == nullptr && root->right == nullptr)
		return root;
	BSTNodeInt* toReturn;
	int maxDiff = -1;

	maxHeightDiffHelper(root, &toReturn, maxDiff);

	return toReturn;
}

int BSTreeInt::maxHeightDiffHelper(BSTNodeInt* node, BSTNodeInt** returnNode, int& maxDiff)
{
	if (node == nullptr)
		return 0;

	if (node->right == nullptr && node->left == nullptr)
		return 1;

	// nadji visinu levog i desno podstabla
	int leftHeight = maxHeightDiffHelper(node->left, returnNode, maxDiff);
	int rightHeight = maxHeightDiffHelper(node->right, returnNode, maxDiff);

	// azuriraj maxDiff ako treba
	if (abs(leftHeight - rightHeight) > maxDiff) {
		maxDiff = abs(leftHeight - rightHeight);
		*returnNode = node;
	}

	// i vrati 1 + trenutna visina
	return 1 + max(leftHeight, rightHeight);
}