#pragma once
#include "Kosarkas.h"
class HashObject
{
private:
	char* key;
	Kosarkas* record;
public:
	HashObject();
	HashObject(const char* k, Kosarkas* v);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	Kosarkas* getRecord() { return record; }
	bool isEqualKey(const char* k) { return strcmp(key,k)==0; }
	void print();
};