#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int

	int i = 0;
	// while (key[i++] != '-');

	uint32_t h = 0;
	while (key[i] != '\0')
		h = h * 101 + key[i++];

	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	uint32_t a = 2654435769;
	return (a * key) >> (32 - 6);
	return 0;
}

