#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	int i = 0;
	unsigned int res = 0;
	while (key[i] != '\0')
		res = res * 101 + key[i++];
	return res;
}

unsigned int HashTable::g(unsigned int key)
{
	unsigned int a = 2654435769;
	return (a*key) >> (32 - 6);
}

