int BSTreeInt::countNodesInRange(int max, int min)
{
    if (root == nullptr)
        return 0;

    return countNodesInRange(root, max, min);
}

int BSTreeInt::countNodesInRange(BSTNodeInt* root, int max, int min)
{
    /*
	
		if (!root)            neefikasno
			return 0;
		if (root->key >= min && root->key <= max)
			return 1 + countNodesInRange(root->left, max, min) + countNodesInRange(root->right, max, min);
		else
			return countNodesInRange(root->left, max, min) + countNodesInRange(root->right, max, min);
	
	*/

    if (root == nullptr)
        return 0;

    int suma = 0;
    if (root->left != nullptr)
        if ((root->left->key >= min && root->left->key <= max)  root->left->right != nullptr)
            suma += countNodesInRange(root->left, min, max);
		
    if (root->right != nullptr)
        if ((root->right->key <= max && root->right->key >= min)  root->right->left != nullptr)
            suma += countNodesInRange(root->right, min, max);

    if (root->key >= min && root->key <= max)
        suma++;
	
    return suma;
}