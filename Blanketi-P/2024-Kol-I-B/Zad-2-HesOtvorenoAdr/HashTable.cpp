#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	
	// 0123456789 
	// 978-X-YYY-ZZZZZ-A

	// krecem od 10-og znaka jer su svi prethodni isti

	int i = 10;
	uint32_t h = 0;
	while (key[i] != '\0') {
		if (key[i] != '-')
			h = h * 101 + key[i];
		++i;
	}

	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	uint32_t const a = 2654435769;
	return (a * key) >> (32 - 6);
}

