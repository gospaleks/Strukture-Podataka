#include "LinkedEdgeInt.h"

LinkedEdgeInt::LinkedEdgeInt() : dest(nullptr), weight(), link(nullptr)
{

}

LinkedEdgeInt::LinkedEdgeInt(LinkedNodeInt* destN, LinkedEdgeInt* linkN)
	: dest(destN), weight(), link(linkN)
{

}

LinkedEdgeInt::LinkedEdgeInt(LinkedNodeInt* destN, double weightN, LinkedEdgeInt* linkN)
	: dest(destN), weight(weightN), link(linkN)
{

}
