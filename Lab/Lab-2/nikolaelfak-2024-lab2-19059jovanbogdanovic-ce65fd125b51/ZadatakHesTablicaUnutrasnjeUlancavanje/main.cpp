#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	
	ChainedScatterObject o1 = ChainedScatterObject("4688773864088", "Jovan", "Bogdanovic", "Miorada Veljkovica");
	ChainedScatterObject o2 = ChainedScatterObject("5443737836504", "Aleksandar", "Gospavic", "Pirottt");
	ChainedScatterObject o3 = ChainedScatterObject("5007714540021", "Veljko", "Veljkovic", "Bor");
	ChainedScatterObject o4 = ChainedScatterObject("0737283077559", "Aca", "Acic", "zajecarr");
	ChainedScatterObject o5 = ChainedScatterObject("4911753524420", "Marko", "Markovic", "Nis");
	ChainedScatterObject o6 = ChainedScatterObject("4806178803220", "Ilija", "Ilijic", "Prokupljee");
	ChainedScatterObject o7 = ChainedScatterObject("8316682557342", "Mitar", "Miric", "Beograd");
	ChainedScatterObject o8 = ChainedScatterObject("5670976548262", "Nebojsa", "Nebojsis", "Novi Sad");
	ChainedScatterObject o9 = ChainedScatterObject("9132542987863", "Vojin", "jevotvic", "Bor");
	ChainedScatterObject o10 = ChainedScatterObject("1074657208442", "Mladen", "Mladenoic", "Knjazevac");
	ChainedScatterObject o11 = ChainedScatterObject("1074657208442", "dddd", "Mladenoic", "Knjazevac");

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
	tablica.insert(o11);

	tablica.print();
	 
	tablica.find(o1.getKey()).print();








}