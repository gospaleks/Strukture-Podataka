#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable tablica(64);
	//TODO: dodati testiranje tablice prema zahtevu zadatka

	ScatterObject o0 = ScatterObject("PI-022-MO", "Stojadin Skala 55", 2001);
	ScatterObject o1 = ScatterObject("PI-015-FF", "BMW M3", 2019);
	ScatterObject o2 = ScatterObject("NI-132-AB", "Mercedes SLC", 2022);
	ScatterObject o3 = ScatterObject("PI-088-CA", "Porshe", 2024);
	ScatterObject o4 = ScatterObject("BG-622-AA", "Peugeot 308", 2011);
	ScatterObject o5 = ScatterObject("PK-032-OE", "Reno Clio", 2006);
	ScatterObject o6 = ScatterObject("NS-456-SE", "Citroen C4", 2007);
	ScatterObject o7 = ScatterObject("NI-242-GX", "Citroen C5", 2013);
	ScatterObject o8 = ScatterObject("PI-011-HJ", "Mercedes CLS", 2017);
	ScatterObject o9 = ScatterObject("PI-067-TX", "Zastava 101", 1998);

	ScatterObject o10 = ScatterObject("BG-622-AA", "Zastava 201", 1977); // duplikat

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

	tablica.find(o4.getKey()).print();
}