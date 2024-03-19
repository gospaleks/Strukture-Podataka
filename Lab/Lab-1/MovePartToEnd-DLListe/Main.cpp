#include"DList.h"

void main()
{
	try {
		DList* list = new DList();
		list->addToHead(6);
		list->addToHead(3);
		list->addToHead(2);
		list->addToHead(7);
		list->addToHead(1);
		list->addToHead(9);
		list->addToHead(4);

		list->printAll();

		list->movePartToEnd(9, 2);

		list->printAll();
		delete list;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}