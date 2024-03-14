#include "CPolynomLL.h"

int main() {
		
	CPolynomLL poly1;

	poly1.Coef(3, -1);
	poly1.Coef(4, 2);
	poly1.Coef(1, 3);
	poly1.Coef(5, -4);
	poly1.Coef(2, 5);
	poly1.Coef(2, 5);

	poly1.Print();

	CPolynomLL poly2;
	poly2.Coef(1, 10);
	poly2.Coef(5, 4);
	poly2.Coef(2, 1);	
	poly2.Coef(6, 5);	

	poly2.Print();


	CPolynomLL* res = CPolynomLL::Add(poly1, poly2);
	res->Print();

	delete res;

	return 0;
}