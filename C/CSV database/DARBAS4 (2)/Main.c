/*
Laboratorinins darbas Nr.4
Darba atliko: Antanas Jurkevicius IIF-13 

Aprasymas:

Programos pradzioje yra atveriamas  CSV failas su informacija apie pasaulio salis.
Failo turinys yra �rasomas � sturkturin� masyv�.
Pagal vartotojo pageidavim�, csv failo turinys yra i�vedamas � ekran�.
Vartotojas taip pat gali iterpti � �� masyv� savo norim� �al� bei informacij� apie j�,
pakeisti jau esam� �al� bei jos atributus, atlikti esamos salies paieska pagal pasirinkta atributa.
Programa gali suskai�iuoti pasirinkto atributo vidurk�, surasti di�iausi� reik�m� ir suskai�iuoti atibut� stulpelio sumas.
Programos gale, visi pakeitimai strukturiniame masyve yra i�saugomi ir v�l �ra�omi � CSV fail�, i� kurio buvo paimti.

*/
#include "Definicijos.h"
#include "Prototipai.h"

void main()
{
	char pavad[st][max];
	int k=0;
	failo_atidarymas(&k,pavad);
	issiuntimas(&k);
	system ("pause");
}