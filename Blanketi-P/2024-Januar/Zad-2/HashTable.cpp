#include"HashTable.h"

unsigned int HashTable::h(const char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(const char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodu unsigned int u [0...M-1]
	return key%m;
}

