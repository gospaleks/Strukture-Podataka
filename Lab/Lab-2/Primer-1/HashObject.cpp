#include "HashObject.h"
using namespace std;

void HashObject::allocateMemory(const char* k, const char* i, const char* p, const char* a)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	ime = new char[strlen(i) + 1];
	strcpy(ime, i);
	prezime = new char[strlen(p) + 1];
	strcpy(prezime, p);
	adresa = new char[strlen(a) + 1];
	strcpy(adresa, a);
}

HashObject::HashObject()
{
	key = NULL;
	ime = NULL;
	prezime = NULL;
	adresa = NULL;
}

HashObject::HashObject(const char* k, const char* i, const char* p, const char* a)
{
	allocateMemory(k, i, p, a);
}

HashObject::~HashObject()
{
	if (key) delete[] key;
	deleteRecord();
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	ime = strcpy(new char[strlen(obj.ime) + 1], obj.ime);
	prezime = strcpy(new char[strlen(obj.prezime) + 1], obj.prezime);
	adresa = strcpy(new char[strlen(obj.adresa) + 1], obj.adresa);
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key) delete[] key;
		deleteRecord();

		allocateMemory(obj.key, obj.ime, obj.prezime, obj.adresa);
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return	(strcmp(this->key, obj.key) == 0) &&
			(strcmp(this->ime, obj.ime) == 0) &&
			(strcmp(this->prezime, obj.prezime) == 0) &&
			(strcmp(this->adresa, obj.adresa) == 0);
}

void HashObject::deleteRecord() {
	if (ime) { delete [] ime; ime = NULL; }
	if (prezime) { delete [] prezime; prezime = NULL; }
	if (adresa) { delete [] adresa; adresa = NULL; }
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (ime != NULL)
	{
		cout << "|" << ime;
	}
	cout << endl;
}