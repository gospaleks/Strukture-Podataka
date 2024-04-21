#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable tablica(64);
	//TODO: dodati testiranje tablice prema zahtevu zadatka

	ScatterObject o1("978-1-111-72345-3", "Naslov 1");
	ScatterObject o2("978-1-111-82145-1", "Naslov 2");
	ScatterObject o3("978-1-111-82945-5", "Naslov 3");
	ScatterObject o4("978-1-111-42365-1", "Naslov 4");
	ScatterObject o5("978-1-111-14841-1", "Naslov 5");
	ScatterObject o6("978-1-111-92245-2", "Naslov 6");
	ScatterObject o7("978-1-111-64891-1", "Naslov 7");
	ScatterObject o8("978-1-111-31647-9", "Naslov 8");
	ScatterObject o9("978-1-111-13146-1", "Naslov 9");
	ScatterObject o10("978-1-111-97681-1", "Naslov 10");
	ScatterObject o12("978-1-111-79818-1", "Naslov Kolizija");
	ScatterObject o11("978-1-111-64897-2", "Naslov KOLIZIJA");


	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o3);
	tablica.insert(o4);
	tablica.insert(o5);
	tablica.insert(o6);
	tablica.insert(o7);
	tablica.insert(o8);
	tablica.insert(o9);
	tablica.insert(o10);
	tablica.insert(o12);
	tablica.insert(o11);

	tablica.print();

	cout << "-------------------------------------------------------------------\n\n\n";

	// Zamena Naslov KOLIZIJA i Naslov 3 jer izmedju njih nije sinonim tako da je prethodnik u stvari Naslov 3
	cout << tablica.swapWithPrevious(o11.getKey()) << "\nPosle swapWithPrevious:\n\n\n";

	tablica.print();
}