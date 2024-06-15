#include "BSTreeInt.h"

void main()
{
    BSTreeInt* stablo = new BSTreeInt();

    stablo->insert(30);
    stablo->insert(35);
    stablo->insert(25);
    stablo->insert(28);
    stablo->insert(15);
    stablo->insert(16);
    stablo->insert(17);
    stablo->insert(18);
    stablo->insert(19);
    stablo->insert(20);
    stablo->insert(10);
    stablo->insert(12);
    stablo->insert(5);
    stablo->insert(6);
    stablo->insert(20);

    cout << stablo->findNodeWithLargestRightSubtree()->key;

    delete stablo;
}
