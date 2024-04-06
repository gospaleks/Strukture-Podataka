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
	if (array) delete[] array;
}

unsigned int OpenScatterTable::c(unsigned int i)
{
	//TODO implementirati sekundarnu funkciju
	return 3*i;
}

bool OpenScatterTable::signup(int playerNumber, const char* name, const char* lastName, const char* yearBorn, int jerseyNumber)
{
	if (count == m)
		throw new exception("Tablica je puna!");

	ScatterObject obj(yearBorn, new Kosarkas(playerNumber, name, lastName, jerseyNumber));

	uint32_t hash = h(obj.getKey());
	uint32_t probe = hash;

	int i = 1;
	while (array[probe].status == 2 && !(array[probe] == obj) && i < m) {
		probe = hash + c(i);
		++i;
	}

	// kosarkas je vec prijavljen
	if (array[probe] == obj)
		return false;
	else {
		array[probe] = obj;
		array[probe].status = 2; // zauzet
		count++;
		return true;
	}
}

int OpenScatterTable::countPlayersBornIn(const char* yearBorn)
{
	/*
		Klk kapiram ovde je ideja da mi kljuc bude godina rodjenja
		jer su onda svi igraci sa istom godinom rodjenja u lancu (tj grupisani kako pise)
	*/

	uint32_t hash = h(yearBorn);
	uint32_t probe = hash;

	int count = 0;
	int i = 1;

	// setnja kroz lanac
	while (array[probe].status != 0 && count < m) {

		// samo ako je polje zauzeto i gadja se kljuc tj godina rodjenja
		if (array[probe].status == 2 && array[probe].isEqualKey(yearBorn))
			count++;

		probe = hash + c(i++);
	}

	return count;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
}