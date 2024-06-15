BSTNodeInt* BSTreeInt::findNodeWithLargestRightSubtree()
{
	BSTNodeInt* maxNode = nullptr;
	int maxVal = 0;
	helper(root, &maxNode, maxVal);
	return maxNode;
}

void BSTreeInt::helper(BSTNodeInt* ptr, BSTNodeInt** maxNode, int& maxVal)
{
	if (ptr == nullptr)	return;

	int desno = countNodes(ptr->right);
	
	if (desno > maxVal) {
		*maxNode = ptr;
		maxVal = desno;
	}
	
	helper(ptr->left, maxNode, maxVal);
}

int BSTreeInt::countNodes(BSTNodeInt* ptr)
{
	if (ptr == nullptr)
		return 0;

	return 1 + countNodes(ptr->left) + countNodes(ptr->right);
}