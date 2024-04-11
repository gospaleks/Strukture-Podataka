#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key; // oblika AA-BBB-CC
	char* nazivModela;
	int godinaProizvodnje;
	//TODO: Izmeniti/dodati atribute objekta prema zahtevima zadatka
public:
	//TODO: Izmeniti metode objekta prema zahtevima zadatka
	HashObject();
	HashObject(const char* k, const char* _nazivModela, int _godinaProizvodnje);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	char* getNazivModela() { return nazivModela; }
	int getGodinaProizvodnje() { return godinaProizvodnje; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};