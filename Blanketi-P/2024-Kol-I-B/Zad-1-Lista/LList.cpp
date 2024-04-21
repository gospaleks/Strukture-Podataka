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

void LList::concatenateParts(LList* list2, int k)
{
	//TODO: Implementirati metodu concatenateParts

	LListNode* insert = head;
	bool nadjen = false;

	// Nalazi prvo pojavljivanje
	while (insert != nullptr && !nadjen) {

		LListNode* tmp1Prev = nullptr;
		LListNode* tmp1 = insert;
		LListNode* tmp2 = list2->getHead();

		int i = 0;
		while (tmp1 != nullptr && tmp2 != nullptr && tmp1->info == tmp2->info) {
			tmp1Prev = tmp1;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			++i;
		}

		if (i >= k) { // naso prvo pojavljivanje
			insert = tmp1Prev;
			nadjen = true;
		}
		else
			insert = insert->next;
	}

	if (!nadjen)
		return;

	// sad svako naredno pojavljivanje dodajemo iza insert
	LListNode* trenutni = insert;
	LListNode* pocetakPrev;
	LListNode* pocetak;
	LListNode* kraj;
	LListNode* krajPrev;

	while (trenutni != nullptr) {

		pocetakPrev = trenutni;
		pocetak = trenutni->next; // pocetak podliste

		krajPrev = trenutni;
		kraj = trenutni->next; // kraj podliste

		int i = 0;
		LListNode* tmp = list2->getHead();
		while (kraj != nullptr && tmp != nullptr && kraj->info == tmp->info) {
			krajPrev = kraj;
			kraj = kraj->next;
			tmp = tmp->next;
			++i;
		}

		if (i >= k) { // nadjeno pojavljivanje prelancaj ga na insert
			
			// ovo resava problem kad su dve liste jedna do druge
			// jer onda nema potrebe za prelancavanjem 
			if (insert != pocetakPrev) {

				LListNode* desnoOdInsert = insert->next;
				insert->next = pocetak;
				krajPrev->next = desnoOdInsert;
				pocetakPrev->next = kraj;

			}

			insert = krajPrev; // azuriraj insert
			trenutni = krajPrev;
		}
		else
			trenutni = trenutni->next;
	}
}

