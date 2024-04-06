#include"OpenScatterTable.h"

void main()
{
	try {
		OpenScatterTable tablica(32);

		// godina rodjenja je kod mn string da ne bi menjao celu implementaciju od bitbucket
		tablica.signup(1, "Pera", "Peric", "2003", 76);
		tablica.signup(2, "Mika", "Mikic", "1948", 48);
		tablica.signup(3, "Zika", "Zikic", "2004", 23);
		tablica.signup(4, "Laza", "Lazic", "1911", 11);
		tablica.signup(5, "Jova", "Jovic", "2003", 33);
		tablica.signup(6, "Mara", "Maric", "2003", 44);
		tablica.signup(7, "Zara", "Zaric", "2004", 55);
		tablica.signup(7, "Zara", "Zaric", "2004", 55);	// ovo nema da doda jer vec ga ima
		tablica.signup(7, "Borivoje", "Surdilovic", "2004", 97);

		tablica.print();

		cout << "Broj igraca rodjenih 2004: " << tablica.countPlayersBornIn("2004") << endl;

	}
	catch (exception* e) // signup baca exception kad nema mesta vise u tablici
	{
		cout << e->what() << endl;
	}
}