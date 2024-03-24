//Proba commita
#include "LList.h"

int main()
{
	LList *list = new LList();
	list->addToTail(1);
	list->addToTail(2);
	list->addToTail(3);
	list->addToTail(4);
	list->addToTail(5);
	list->addToTail(6);
	list->addToTail(7);
	list->addToTail(8);
	list->addToTail(9);
	list->addToTail(0);
	
	list->printAll();

	// zadavati podlistu sa parnim brojem elemenata
	// kao sto je receno u zadatku
	cout << list->SwapPairs(4, 8) << endl;

	list->printAll();

	delete list;
	return 0;
}