#include "LList.h"

int main()
{
	LList *list = new LList();
	list->addToHead(6);
	list->addToHead(6);
	list->addToHead(3);
	list->addToHead(2);
	list->addToHead(7);
	list->addToHead(9);
	list->addToHead(1);
	list->addToHead(7);
	list->addToHead(9);
	list->addToHead(4);
	
	list->printAll();

	LList* nova = list->SplitOrMove();
	cout << "Nova lista:\n";
	nova->printAll();

	// u prinicpu posle ovoga u staru listu ostaju
	// samo elemenit koji su imali duplikate
	cout << "\nStara lista posle SplitOrMove():\n";
	list->printAll();
	
	delete nova;
	delete list;
	return 0;
}