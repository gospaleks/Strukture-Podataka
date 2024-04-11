#include "HashObject.h"
using namespace std;
//TODO: Izmeniti metode objekta prema zahtevima zadatka
HashObject::HashObject()
{
	key = NULL;
	nazivModela = NULL;
	godinaProizvodnje = 0;
}

HashObject::HashObject(const char* k, const char* _nazivModela, int _godinaProizvodnje)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	nazivModela = new char[strlen(_nazivModela) + 1];
	strcpy(nazivModela, _nazivModela);
	godinaProizvodnje = _godinaProizvodnje;
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
	if (nazivModela)
		delete[] nazivModela;
	godinaProizvodnje = 0;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	nazivModela = strcpy(new char[strlen(obj.nazivModela) + 1], obj.nazivModela);
	godinaProizvodnje = obj.godinaProizvodnje;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete [] key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);

		if (nazivModela)
			delete [] nazivModela;
		nazivModela = new char[strlen(obj.nazivModela) + 1];
		strcpy(nazivModela, obj.nazivModela);

		this->godinaProizvodnje = obj.godinaProizvodnje;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) &&
		(strcmp(this->nazivModela, obj.nazivModela) == 0) &&
		(this->godinaProizvodnje == obj.godinaProizvodnje);
}

void HashObject::deleteRecord() {
	if (nazivModela)
		delete[] nazivModela;
	godinaProizvodnje = 0;
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (nazivModela != NULL)
	{
		cout << "|" << nazivModela;
		cout << "|" << godinaProizvodnje;
	}
	cout << endl;
}