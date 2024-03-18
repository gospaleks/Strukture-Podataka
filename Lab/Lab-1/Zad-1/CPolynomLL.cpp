#include "CPolynomLL.h"

CPolynomLL::CPolynomLL()
{
	head = nullptr;
}

CPolynomLL::~CPolynomLL()
{
	while (!Empty())
		DeleteFromHead();
}

bool CPolynomLL::Empty()
{
	return head == nullptr;
}

Node* CPolynomLL::GetHead()
{
	return head;
}

void CPolynomLL::DeleteFromHead()
{
	if (Empty())
		return;

	Node* tmp = head;
	head = head->next;
	delete tmp;
}

void CPolynomLL::Coef(int exp, double coef)
{	
	// Ako je lista prazna ili ako je element veceg stepena nego trenutni najveci
	if (Empty() || exp > head->exp)
		head = new Node(exp, coef, head);
	
	else
	{
		Node* prev = nullptr;
		Node* curr = head;

		while (curr != nullptr && exp < curr->exp) {
			prev = curr;
			curr = curr->next;
		}

		// Ovo je add to tail bukv (najnizi exp)
		if (curr == nullptr) {
			prev->next = new Node(exp, coef);
		}

		// Ako je dodat element sa istim eksponentom samo saberi coef
		else if (exp == curr->exp)
			curr->coef += coef;

		// Ovo je umetanje izmedju prev i curr
		else {
			prev->next = new Node(exp, coef, curr);
		}
	}

}

CPolynomLL* CPolynomLL::Add(const CPolynomLL& poly1, const CPolynomLL& poly2)
{
	/*
 		Mozda bolje resenje:
   		Posto u Coef(..) pokrivam slucaj kad se dodaje element s isti eksponent,
     		moze da se prodje samo kroz poly1 i poly2 i redom da se dodaju svi i f-ja Coef ce sredi duplikate

   		while (ptr1 != nullptr) {
     			result->Coef(ptr1->exp, ptr1->coef);
			ptr1 = ptr1->next;
		}

     		while (ptr2 != nullptr) {
     			result->Coef(ptr2->exp, ptr2->coef);
			ptr2 = ptr2->next;
		}
 	*/

	
	CPolynomLL* result = new CPolynomLL();

	Node* ptr1 = poly1.head;
	Node* ptr2 = poly2.head;

	while (ptr1 != nullptr && ptr2 != nullptr) {

		while (ptr1 != nullptr && ptr1->exp > ptr2->exp) {
			result->Coef(ptr1->exp, ptr1->coef);
			ptr1 = ptr1->next;
		}

		while (ptr2 != nullptr && ptr2->exp > ptr1->exp) {
			result->Coef(ptr2->exp, ptr2->coef);
			ptr2 = ptr2->next;
		}

		if (ptr1->exp == ptr2->exp) {
			result->Coef(ptr1->exp, ptr1->coef + ptr2->coef);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}

	while (ptr1 != nullptr) {
		result->Coef(ptr1->exp, ptr1->coef);
		ptr1 = ptr1->next;
	}

	while (ptr2 != nullptr) {
		result->Coef(ptr2->exp, ptr2->coef);
		ptr2 = ptr2->next;
	}

	return result;
}

void CPolynomLL::Print()
{
	if (Empty())
		return;
	
	std::cout << "P(x) = ";

	Node* tmp = head;
	while (tmp != nullptr) {
		tmp->Print();
		tmp = tmp->next;
	}

	std::cout << std::endl;
}
