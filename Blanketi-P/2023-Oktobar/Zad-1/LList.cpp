#include "LList.h"

void LList::rearrange(int v1, int v2, int k)
{
	// nalazi pokazivac na k-ti element u listi
	LListNode* kPtr = head;
	int i = 0;
	while (kPtr != nullptr && i < k) {
		kPtr = kPtr->next;
		++i;
	}

	// ako k-ti element ne postoji ili je poslednji element prekini
	// ovo ne mora da se proverava jer kaze da ce sigurno bude u granicama sve
	if (kPtr == nullptr || kPtr->next == nullptr)
		return;

	LListNode* left = head;
	LListNode* leftPrev = nullptr;
	LListNode* right = kPtr->next;
	LListNode* rightPrev = kPtr;

	while (left != kPtr && right != nullptr) {

		// element left treba zameniti
		if (left->info < v1) {

			// nadji prvi desno od k koji moze da se zameni sa left
			while (right != nullptr && right->info < v2) {
				rightPrev = right;
				right = right->next;
			}
		
			// zameni left and right
			// spec slucaj ako je left prvi element liste
			if (leftPrev == nullptr)
				head = right;
			else
				leftPrev->next = right;

			LListNode* tmp = left->next;
			rightPrev->next = left;
			left->next = right->next;
			right->next = tmp;

			// posto sam ima zamenio mesta a ocu da nastavim pretragu mora
			// se odradi swap da bi lepo nastavio
			// znaci ovo nije zamena mesta elementima, nego pokazivacima (sto ne utice na listu)
			swap(leftPrev, rightPrev);
			swap(left, right);
		}

		// predji na sledeci element sa leve strane od k-tog
		leftPrev = left;
		left = left->next;

	}
}

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
