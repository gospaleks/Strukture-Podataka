#include "OpenScatterTable.h"
using namespace std;


OpenScatterTable::OpenScatterTable(unsigned int length)
{
	count = 0;
	m = length;
	array = new ScatterObject[m];
}


OpenScatterTable::~OpenScatterTable()
{
	delete[] array;
}

unsigned int OpenScatterTable::c(unsigned int i)
{
	//TODO implementirati sekundarnu funkciju
	return i*i;
}

void OpenScatterTable::insert(ScatterObject obj)
{
	//TODO: Implementirati insert funkciju tablice sa otvorenim adresiranjem za smeštanje sinonima

	uint32_t hash = h(obj.getKey());
	uint32_t probe = hash;

	if (array[probe].status == 2) {

		// cout << "kolizija: " << probe << ", " << obj.getRecord() << endl;

		int i = 1;
		while (array[probe].status == 2 && i < m) {
			probe = (hash + c(i++)) % m;
		}

		// provera zbog kog uslova je ispao
		if (i == m)  // tablica je puna
			return;
	}
	
	array[probe] = obj;
	array[probe].status = 2;
	count++;
}

bool OpenScatterTable::swapWithPrevious(char* key)
{
	//TODO: Implementirati swapWithPrevious funkciju tablice sa otvorenim adresiranjem za smeštanje sinonima 
	//koja u tablici pronalazi konkretni objekat i ukoliko on nije na adresi u koju se hešira njegov ključ, na mesto prethodnog sininima.

	uint32_t hash = h(key);

	if (array[hash].status == 2) {
			
		if (array[hash].isEqualKey(key)) // vec je na mestu gde se hesira njegov kljuc
			return false;
	
		int i = 1;
		uint32_t prethodni = hash;
		uint32_t sledeci = (prethodni + c(i++)) % m;

		while (array[sledeci].status != 0 && !array[sledeci].isEqualKey(key)) {
			
			// ako jeste sinonim (jer mogu da se dese rupe u 'lancu') 
			// tj da se stane na podatak koji je mozda prirodno tu hesiran ali se samo zadesio na putu
			if (array[sledeci].status == 2 && h(key) == h(array[sledeci].getKey()))
				prethodni = sledeci;
			
			sledeci = (hash + c(i++)) % m;	
		}

		// ako je nadjen i ako su taj i prethodni sinonimi onda zameni
		if (array[sledeci].isEqualKey(key) && h(array[sledeci].getKey()) == h(array[prethodni].getKey())) {
			swap(array[prethodni], array[sledeci]);
			return true;
		}

	}

	return false;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
}