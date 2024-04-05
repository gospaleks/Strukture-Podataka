#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	unsigned int a = 2654435769;
	return (a * key) >> (32 - 6);	// 6 je broj bitova za M
//	return key%m;
}

