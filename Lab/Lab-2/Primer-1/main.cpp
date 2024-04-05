#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	ChainedScatterObject o0("2907982750051", "Nikola", "Davidovic", "Nikole Tesle 10");
	ChainedScatterObject o1("1110002745031", "Teodora", "Bozic", "Bulevar Nemanjica 25");
	ChainedScatterObject o2("2603002732517", "Aleksandar", "Djordjevic", "Ustanicka ulica 10");
	ChainedScatterObject o3("2706985730058", "Pera", "Peric", "Jovana Skerlica 15");
	ChainedScatterObject o4("2548520244545", "Milan", "Velickovic", "Bulevar Nemanjica 34");
	ChainedScatterObject o5("1708978541263", "Nikola", "Milic", "Nikole Tesle 25");
	ChainedScatterObject o6("0809002752418", "Milos", "Arsic", "Ratnih heroja 47");
	ChainedScatterObject o7("1911998762819", "Aleksa", "Jovanovic", "Nikole Tesle 14");
	ChainedScatterObject o8("1905999751518", "Jovan", "Davidovic", "Sedmi juli 6");
	ChainedScatterObject o9("2202003752418", "Dusan", "Ilic", "Bulevar Nemanjica 87");
	ChainedScatterObject o10("2202003752418", "Aleksandar", "Gospavic", "Takovska 46");

	tablica.insert(o0);
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

	tablica.print();

	tablica.find((char*)"1911998762819").print();
}