#include <iostream>
using namespace std;

enum EEtat
{
	vide, palette, rouleau
};

struct SPalette
{
	int poids;
	char reference[20];
};

struct SRouleau
{
	float longeur;
	int numero;
};

union UContenue
{
	SPalette paletteCasier;
	SRouleau rouleauCasier;
};

struct SCasier
{
	int px;
	int py;
	EEtat etat;
	UContenue contenue;
};


int main()
{
	cout << "Transgerbeur";
	SRouleau ro1 = { 54.23 , 10 };
	SPalette pa1;
	pa1.poids = 54;
	strcpy_s(pa1.reference, "hugo");

	SPalette pa2;
	pa2.poids = 154;
	strcpy_s(pa2.reference, "hgfhidg");

	EEtat etatC1 = vide;

	UContenue cont;
	cont.paletteCasier = pa1;
	cont.rouleauCasier = ro1;

	SCasier C1;
	C1.etat = palette;
	C1.contenue.paletteCasier = pa1;
	C1.px = 2;
	C1.py = 3;

	SCasier C2;
	C2.etat = palette;
	C2.contenue.paletteCasier = pa2;
	C2.px = 3;
	C2.py = 3;

	SCasier tabCasier[9];

	tabCasier[0] = C1;
	tabCasier[1] = C2;

	cout << " " << sizeof(C2) << " " << sizeof(C1) << " " << sizeof(tabCasier) << " " << sizeof(cont);

	return(0);
}