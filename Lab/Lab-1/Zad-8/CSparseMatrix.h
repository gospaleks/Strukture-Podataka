#pragma once
#include <iostream>
#include "Node.h"

template <class T>
class CSparseMatrix
{
private:
	Node<T>** vrste;
	Node<T>** kolone;

	int n, m;

public:
	CSparseMatrix(int _n, int _m);
	~CSparseMatrix();

	void SetAt(int i, int j, T el);
	T GetAt(int i, int j);
	void Print();
};

template<class T>
inline CSparseMatrix<T>::CSparseMatrix(int _n, int _m)
{
	n = _n;
	m = _m;

	vrste = new Node<T>*[n];
	kolone = new Node<T>*[m];

	for (int i = 0; i < n; i++)
		vrste[i] = nullptr;

	for (int i = 0; i < m; i++)
		kolone[i] = nullptr;
}

template<class T>
inline CSparseMatrix<T>::~CSparseMatrix()
{
	// Dovoljno je po redovima da brisemo to ce obrise sve cvorove
	// Ako brisem i po kolonama imacu duplo brisanje i baca izuzetak
	for (int i = 0; i < n; i++)
	{
		Node<T>* temp = vrste[i];
		while (temp != nullptr)
		{
			Node<T>* temp2 = temp;
			temp = temp->vLink;
			delete temp2;
		}
	}

	// Na kraju samo pokazivace smaknem
	delete[] vrste;
	delete[] kolone;
}

template<class T>
inline void CSparseMatrix<T>::SetAt(int i, int j, T el)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		throw std::exception("Indeksi nisu dobri!");


	Node<T>* newNode = new Node<T>(i, j, el);

	// Za vrste

	// Ako nema nista u toj vrsti onda samo dodajemo novi element
	if (vrste[i] == nullptr)
		vrste[i] = newNode;

	// Ako vec ima nesto u toj vrsti onda trazimo mesto gde treba da se ubaci
	else {
		Node<T>* prev = nullptr;
		Node<T>* curr = vrste[i];
		while (curr != nullptr && curr->j <= j) {

			// spec slucaj ako setujemo vec postojeci element matrice
			if (curr->j == j) {
				curr->el = el;
				delete newNode;
				return;
			}

			prev = curr;
			curr = curr->vLink;
		}

		// Spec slucaj ako novi element ide na prvo mesto u vrsti
		if (prev == nullptr) {
			newNode->vLink = curr;
			vrste[i] = newNode;
		}
		// Inace ga ubacujemo izmedju dva elementa
		else {
			prev->vLink = newNode;
			newNode->vLink = curr;
		}
	}

	// Isto sve to samo za kolone

	if (kolone[j] == nullptr)
		kolone[j] = newNode;

	else {
		Node<T>* prev = nullptr;
		Node<T>* curr = kolone[j];
		while (curr != nullptr && curr->i <= i) {

			if (curr->i == i) {
				curr->el = el;
				delete newNode;
				return;
			}

			prev = curr;
			curr = curr->kLink;
		}

		if (prev == nullptr) {
			newNode->kLink = curr;
			kolone[j] = newNode;
		}
		else {
			prev->kLink = newNode;
			newNode->kLink = curr;
		}
	}
}

template<class T>
inline T CSparseMatrix<T>::GetAt(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		throw std::exception("Indeksi nisu dobri!");
	
	if (vrste[i] == nullptr)
		return T();
	else {
		Node<T>* tmp = vrste[i];
		while (tmp != nullptr && tmp->j < j)
			tmp = tmp->vLink;

		if (tmp == nullptr)
			return T();
		else
			return tmp->el;
	}
}

template<class T>
inline void CSparseMatrix<T>::Print()
{
	for (int i = 0; i < n; i++)
	{
		Node<T>* temp = vrste[i];
		for (int j = 0; j < m; j++)
		{
			if (temp != nullptr && temp->j == j)
			{
				std::cout << temp->el << " ";
				temp = temp->vLink;
			}
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
