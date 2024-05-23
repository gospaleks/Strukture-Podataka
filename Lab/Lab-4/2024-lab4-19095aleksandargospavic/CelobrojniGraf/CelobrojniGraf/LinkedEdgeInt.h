#pragma once

class LinkedNodeInt;

class LinkedEdgeInt
{
public:
	LinkedNodeInt* dest;
	double weight;
	LinkedEdgeInt* link;

	LinkedEdgeInt();
	LinkedEdgeInt(LinkedNodeInt* destN, LinkedEdgeInt* linkN);
	LinkedEdgeInt(LinkedNodeInt* destN, double weightN, LinkedEdgeInt* linkN);
};
