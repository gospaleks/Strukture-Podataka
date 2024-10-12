#include "LList.h"


LList::LList()
{
	head=NULL;
}


LList::~LList()
{
	while(!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head==NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if(!isEmpty())
	{
		LListNode* tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode *tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		el = head->info;
		delete head;
		head = NULL;
	}
	else
	{
		LListNode* prev = head;
		LListNode *tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		el = tmp->info;
		delete tmp;
		prev->next = NULL;
	}
	return el;
}

LListNode* LList::findNodePtr(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode *ret = head;
	while(ret!=NULL && ret->info!=el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if(isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if(isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		throw new exception("Node doesn't exist");
	if(tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode *tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->print() << " ";
		tmp=tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if(isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
	if (head->isEqual(el)) 
	{
		LListNode *tmp = head;
		head = head->next;
		delete tmp;
	}
	else 
	{
		LListNode *pred, *tmp; 
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
			  pred = pred->next, tmp = tmp->next);
		if (tmp != NULL) 
		{
			pred->next = tmp->next;
			delete tmp;
		}
    }
}

LListNode* LList::removeNodeFromHead()
{
	if(isEmpty())
		return NULL;
	LListNode *tmp = head;
	head = head->next;
	return tmp;
}

void LList::umetanjeNaPocetak(int vrednost)
{
	LListNode* novi = new LListNode(vrednost);
	novi->next = head;
	head = novi;
}

void LList::umetanjePosleZadatog(int vrednost, int posleKog)
{
	LListNode* temp = head;
	if (head == nullptr) {
		umetanjeNaPocetak(vrednost);
		return;
	}
	//sad trazimo
	while (temp != nullptr && temp->info != posleKog)
		temp = temp->next;
	if (temp == nullptr) {
		return;
	}
	//nasoga
	LListNode* novi = new LListNode(vrednost);
	novi->next = temp->next;
	temp->next = novi;
}

void LList::umetanjeUSortiranuListu(int vrednost)
{
	if (head == nullptr) {
		umetanjeNaPocetak(vrednost);
		return;
	}
	if (vrednost < head->info) {
		umetanjeNaPocetak(vrednost);
		return;
	}
	LListNode* temp = head;
	while (temp->next != nullptr && temp->next->info < vrednost) {
		temp = temp->next;
	}
	LListNode* novi = new LListNode(vrednost);
	novi->next = temp->next;
	temp->next = novi;
}

void LList::brisanjeSaPocetka()
{
	if (!head)
		return;
	LListNode* temp = head;
	head = head->next;
	delete temp;
}

void LList::brisanjeElemnta(int vrednost)
{
	if (!head) {
		return;
	}
	LListNode* temp = head;
	if (head->info == vrednost){
		brisanjeSaPocetka();
		return;
	}
	while (temp->next != nullptr && temp->next->info != vrednost) {
		temp = temp->next;
	}
	if (!temp) {
		return;
	}
	LListNode* pok = temp->next;
	temp->next = temp->next->next;
	delete pok;
}

void LList::zameniElementISledeci(int vrednost)
{
	if (isEmpty())
		return;
	LListNode* prt = head;
	if (prt->next == nullptr)
		return;
	if (head->info == vrednost) {
		head = prt->next;
		prt->next = head->next;
		head->next = prt;
		return;
	}
	while (prt->next != nullptr && prt->next->info != vrednost)
		prt = prt->next;
	if (prt->next == nullptr)
		return;
	LListNode* temp = prt->next;
	prt->next = temp->next;
	temp->next = prt->next->next;
	prt->next->next = temp;

}

void LList::staviNaPocetak(int vrednost)
{
	if (head == nullptr)
		return;

	if (head->info == vrednost) {
		return;
	}
	LListNode* ptr = head;
	while (ptr->next != nullptr && ptr->next->info != vrednost) {
		ptr = ptr->next;
	}
	if (ptr->next == nullptr)
		return;
	LListNode* ptr2 = ptr->next;
	ptr->next = ptr2->next;
	ptr2->next = head;
	head = ptr2;
	
}

void LList::staviSegmentNaPocetak(int vrednost1, int vrednost2)
{
	if (head == nullptr)
		return;
	if (head->info == vrednost1)
		return;
	if (vrednost1 == vrednost2) {
		staviNaPocetak(vrednost2);
		return;
	}
	LListNode* ptr = head;
	while (ptr->next != nullptr && ptr->next->info != vrednost1)
		ptr = ptr->next;
	if (ptr->next == nullptr)
		return;

	LListNode* ptr2 = ptr->next->next;
	while (ptr2 != nullptr && ptr2->info != vrednost2)
		ptr2 = ptr2->next;
	if (ptr2 == nullptr)
		return;

	LListNode* ptr3 = ptr2->next;
	ptr2->next = head;
	head = ptr->next;
	ptr->next = ptr3;
}

void LList::inverSublist(int data1, int data2)
{
	if (isEmpty() || (data1 == data2) || (head->next == nullptr))
		return;

	// Nalazimo taj koj nam treba i prethodni za data1
	LListNode* temp1prev = nullptr;
	LListNode* temp1 = head;
	while (temp1 != nullptr && temp1->info != data1) {
		temp1prev = temp1;
		temp1->next;
	}
	if (temp1->next == nullptr)
		return;

	// Nalazimo data2
	LListNode* temp2 = temp1->next->next;
	while (temp2 != nullptr && temp2->info != data2)
		temp2 = temp2->next;
	if (temp2 == nullptr)
		return;

	temp2 = temp2->next;

	// Ako je data1 na head pravi novi koji sluzi kao pomocni da ne bi menjao ceo kod
	// nego samo da iskopiram :) i da napisem da je novi na pocetku liste i iskoristim
	// isti kod i onda kazem da je head isto sto i taj novi
	if (head == temp1) {
		LListNode novi(0, temp1);

		LListNode* p = novi.next;
		LListNode* d = nullptr;
		while (p->next != temp2) {
			d = p->next;
			p->next = d->next;
			d->next = novi.next;
			novi.next = d;
		}
		head = novi.next;
		return;
	}

	// Normalan slucaj i neam veze ako je posle data2 nullptr
	LListNode* p = temp1prev->next;
	LListNode* d = nullptr;
	while (p->next != temp2) {
		d = p->next;
		p->next = d->next;
		d->next = temp1prev->next;
		temp1prev->next = d;
	}
}

void LList::exchange(int data1, int data2)
{
	if (isEmpty() || data1 == data2 || head->next == nullptr)
		return;

	LListNode* temp1prev = nullptr;
	LListNode* temp1 = head;
	LListNode* temp1next = nullptr;

	LListNode* temp2prev = nullptr;
	LListNode* temp2 = head;
	LListNode* temp2next = nullptr;

	while(temp1 != nullptr && temp2 != nullptr && (temp1->info != data1 || temp2->info != data2)) {
		if (temp1->info != data1) {
			temp1prev = temp1;
			temp1 = temp1->next;
		}
		if (temp2->info != data2) {
			temp2prev = temp2;
			temp2 = temp2->next;
		}
	}

	if (temp1 == nullptr || temp2 == nullptr)
		return;

	temp1next = temp1->next;
	temp2next = temp2->next;

	if (temp1prev != nullptr) 
		temp1prev->next = temp2;
	else
		head = temp2;

	if (temp2prev != nullptr)
		temp2prev->next = temp1;
	else
		head = temp1;

	temp1->next = temp2next;
	temp2->next = temp1next;
}

bool LList::moveSectionToHead(int start, int end)
{
	if (head == nullptr || head->next == nullptr)
		return false;
	
	if (head->info == start)
		return true;

	LListNode* temp1prev = head;
	while (temp1prev->next != nullptr && temp1prev->next->info != start)
		temp1prev = temp1prev->next;
	if (temp1prev->next == nullptr)
		return false;

	LListNode* temp2 = temp1prev->next->next;
	while (temp2 != nullptr && temp2->info != end)
		temp2 = temp2->next;
	if (temp2 == nullptr)
		return false;

	LListNode* temp1 = temp1prev->next;

	temp1prev->next = temp2->next;
	temp2->next = head;
	head = temp1;

	return true;
}
