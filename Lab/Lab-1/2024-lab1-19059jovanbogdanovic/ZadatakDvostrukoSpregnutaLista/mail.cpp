#include"DList.h"

void main()
{
	DList *list = new DList();
	list->insertSorted(6);
	list->printAll();
	list->insertSorted(3);
	list->printAll();
	list->insertSorted(2);
	list->printAll();
	list->insertSorted(7);
	list->printAll();
	list->insertSorted(1);
	list->printAll();
	list->insertSorted(9);
	list->printAll();
	list->insertSorted(4);
	list->printAll();
	list->insertSorted(2);
	list->printAll();
	list->insertSorted(9);
	list->printAll();
	list->insertSorted(1);
	list->printAll();

	delete list;
}