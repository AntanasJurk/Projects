/*
Laboratorinins darbas Nr.4
Darba atliko: Antanas Jurkevicius IIF-13 

Aprasymas:

Programos pradzioje yra atveriamas  CSV failas su informacija apie pasaulio salis.
Failo turinys yra árasomas á sturkturiná masyvà.
Pagal vartotojo pageidavimà, csv failo turinys yra iðvedamas á ekranà.
Vartotojas taip pat gali iterpti á ðá masyvà savo norimà ðalá bei informacijà apie jà,
pakeisti jau esamà ðalá bei jos atributus, atlikti esamos salies paieska pagal pasirinkta atributa.
Programa gali suskaièiuoti pasirinkto atributo vidurká, surasti diþiausià reikðmæ ir suskaièiuoti atibutø stulpelio sumas.
Programos gale, visi pakeitimai strukturiniame masyve yra iðsaugomi ir vël áraðomi á CSV failà, ið kurio buvo paimti.

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