#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Kosarkas
{
private:
	int playerNumber;
	char* name;
	char* lastName;
	int jerseyNumber;
public:
	Kosarkas();
	Kosarkas(int playerNumber, const char* name, const char* lastName, int jerseyNumber);
	Kosarkas(Kosarkas const& obj);
	~Kosarkas();

	Kosarkas& operator = (Kosarkas const& obj);
	bool operator == (Kosarkas const& obj);

	void deleteRecord();
	
	int getPlayerNumber() const { return playerNumber; }
	char* getName() const { return name; }
	char* getLastName() const { return lastName; }
	int getJerseyNumber() const { return jerseyNumber; }

	void print();
};

