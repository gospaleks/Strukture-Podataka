#include "LList.h"

void main()
{
	int data1[] = { 7, 9, 8, 1, 2, 3, 4, 6, 8, 3, 1, 2, 3, 5, 6, 4, 8, 1, 2, 3, 4, 5, 9, 0 };
	int data2[] = { 1, 2, 3, 4, 5 };
	int k = 3;

	LList list1;
	for (int i = 23; i >= 0; i--)
	{
		list1.addToHead(data1[i]);
	}
	LList list2;
	for (int i = 4; i >= 0; i--)
	{
		list2.addToHead(data2[i]);
	}
	list1.printAll();
	list1.concatenateParts(&list2, k);
	list1.printAll();

	//TODO: Dodati jos test podataka (ako je potrebno)

	// primer kad su dve podliste jedna do druge
	//int data1[] = { 1, 2, 3, 1, 2, 3, 4, 6, 8, 3, 1, 2, 3, 5, 6, 4, 8, 1, 2, 3, 4, 5, 9, 0 };
	//int data2[] = { 1, 2, 3, 4, 5 };
	//int k = 3;

	//LList list1;
	//for (int i = 23; i >= 0; i--)
	//{
	//	list1.addToHead(data1[i]);
	//}
	//LList list2;
	//for (int i = 4; i >= 0; i--)
	//{
	//	list2.addToHead(data2[i]);
	//}
	//list1.printAll();
	//list1.concatenateParts(&list2, k);
	//list1.printAll();
}