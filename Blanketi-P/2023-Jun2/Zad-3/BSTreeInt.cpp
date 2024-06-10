/*
	n - d < np < n
	Posto se trazi bar jedan cvor za koji ovo vazi
	Moze se uoci da je dovoljno samo prvi da proverimo
	Jer ako prvi nije onda nije nijedan ispod
	bar se meni tako cini :)

	Takodje dovoljno proveriti samo levo podstablo
*/

int BSTreeInt::countSmaller(BSTNodeInt* ptr, int d)
{
	if (ptr == nullptr)
		return 0;

	if (ptr->left == nullptr && ptr->right == nullptr)
		return 0;

	if (ptr->left->key > ptr->key - d)
		return 1 + countSmaller(ptr->left, d) + countSmaller(ptr->right, d);
	else
		return countSmaller(ptr->left, d) + countSmaller(ptr->right, d);
}

int BSTreeInt::countSmaller(int d)
{
	return countSmaller(root, d);
}