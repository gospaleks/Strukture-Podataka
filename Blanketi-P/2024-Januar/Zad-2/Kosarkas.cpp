#include "Kosarkas.h"

Kosarkas::Kosarkas()
{
	playerNumber = 0;
	name = nullptr;
	lastName = nullptr;
	jerseyNumber = 0;
}

Kosarkas::Kosarkas(int playerNumber, const char* name, const char* lastName, int jerseyNumber)
{
	this->playerNumber = playerNumber;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->lastName = new char[strlen(lastName) + 1];
	strcpy(this->lastName, lastName);
	this->jerseyNumber = jerseyNumber;
}

Kosarkas::Kosarkas(Kosarkas const& obj)
{
	playerNumber = obj.playerNumber;
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	lastName = new char[strlen(obj.lastName) + 1];
	strcpy(lastName, obj.lastName);
	jerseyNumber = obj.jerseyNumber;
}

Kosarkas::~Kosarkas()
{
	deleteRecord();
}

Kosarkas& Kosarkas::operator=(Kosarkas const& obj)
{
	if (this != &obj) {

		deleteRecord();

		playerNumber = obj.playerNumber;

		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

		lastName = new char[strlen(obj.lastName) + 1];
		strcpy(lastName, obj.lastName);


		jerseyNumber = obj.jerseyNumber;

	}
	return *this;
}

bool Kosarkas::operator==(Kosarkas const& obj)
{
	if (playerNumber == obj.playerNumber &&
		jerseyNumber == obj.jerseyNumber) {

		if (strcmp(name, obj.name) == 0 && strcmp(lastName, obj.lastName) == 0)
			return true;
	}
	return false;
}

void Kosarkas::deleteRecord()
{
	if (name) delete [] name;
	if (lastName) delete [] lastName;
}

void Kosarkas::print()
{
	cout << name;
}
