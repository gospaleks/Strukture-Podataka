#pragma once

//#include "LinkedEdgeInt.h"
#include "LinkedNodeInt.h"

class GraphAsListsInt
{
protected:
	LinkedNodeInt* start;
	long nodeNum;
public:
	GraphAsListsInt();
	~GraphAsListsInt();

	LinkedNodeInt* findNode(const int& data) const;
	LinkedEdgeInt* findEdge(const int& dataSrc, const int& dataDest) const;

	void insertNode(const int& data);
	bool insertEdge(const int& dataSrc, const int& dataDest, const double& weight = 0);

private:
	void deleteEdgeToNode(const LinkedNodeInt* pDest);
public:
	bool deleteEdge(const int& dataSrc, const int& dataDest);
	bool deleteNode(const int& data);

	void print() const;

private:
	void setStatusForAllNodes(int status) const;
public:
	long breadthFirstTraversal(const int& data) const;
	long depthFirstTraversalIterative(const int& data) const;
private:
	long depthFirstTraversalRecursive(LinkedNodeInt* ptr) const;
public:
	long depthFirstTraversalRecursive(const int& data) const;

	long topologicalOrderTravrsal() const;

	void uNeusmereni();

	//Januar 2024
	bool arePathPossible(LinkedNodeInt* pocetak, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid);
	bool v2(LinkedNodeInt* start, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid);
	bool v2pom(LinkedNodeInt* start, LinkedNodeInt* end); //da li postoji put

	//Kolokvijum 2 gurpaA 2023
	int subgrapfCnt(int p);
	bool bfsHelperVrdnost(LinkedNodeInt* ptr, int p);

	//Kolokvijum 2 grupaB 2023
	int doesConnentedComponentExists(int k);
	bool bfsHelperZaK(LinkedNodeInt* ptr, int k);

	//Decembar 2023
	int LongestSimpleCycle();
	int pretragaZaCikl(LinkedNodeInt* ptr);

	//Oktobar 2023
	bool canReach(int A, int B, int noNodes);

	//Jun2 2023
	bool isCyclic();
	bool pretraga(LinkedNodeInt* ptr, int trenstatus);

	//Da li je graf jako poezan
	bool daLiJeJakoPovezan();
	bool dfsPretrage(LinkedNodeInt* ptr);

	//Oktobar2 2022
	bool pathExists(LinkedNodeInt* a, LinkedNodeInt* b, LinkedNodeInt* c, LinkedNodeInt* d);
	bool dfsHelperObicanPut(LinkedNodeInt* a, LinkedNodeInt* b);

	//Oktobar 2022
	void conectGraph();
	bool egdeExists(LinkedNodeInt* a, LinkedNodeInt* b);
	bool isConnected();

	//Jun 2022
	int getMaxConnectionsDisjointSubgraph();
	int bfsHelperGrane(LinkedNodeInt* ptr);

	//Septembar 2022
	int numOfSameFlights(LinkedNodeInt* ap1, LinkedNodeInt* ap2, LinkedNodeInt* gaol);
	void bfsHelper(LinkedNodeInt* ptr, LinkedNodeInt* cilj);

	//Jun2 2021
	int reachalInNHoops(LinkedNodeInt* a, int n);
	int raachalInHoopsV2(LinkedNodeInt* a, int n);
};

