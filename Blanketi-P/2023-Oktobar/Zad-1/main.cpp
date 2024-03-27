#include "LList.h"

int main()
{
	LList *list = new LList();
	
	list->addToTail(5);
	list->addToTail(1);
	list->addToTail(2);
	list->addToTail(8);
	list->addToTail(100);
	list->addToTail(1);
	list->addToTail(8);
	list->addToTail(2);
	list->addToTail(6);
	
	list->printAll();

	list->rearrange(3, 5, 4);

	list->printAll();

	delete list;
	return 0;
}