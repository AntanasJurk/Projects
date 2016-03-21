#include "Definicijos.h"
#include "Struktura.h"
void isvedimas_i_ekrana ()
{
	int j;
	system ("cls");
	pavad();
	for(j=1;j<103;j++)						//Strukturos masyvo turinys isvedamas i ekrana
		{									//Isvedami strukturinio masyvo elementai, vienas po kito
			printf ("%d  ",j);												
			printf ("%-25s  ",mas[j].pav);
			printf ("%15d  ",mas[j].populiacija);
			printf ("%15d  ",mas[j].plotas);
			printf ("%15.1f  ",mas[j].poptankis);
			printf ("%15.1f  ",mas[j].pakrante);
			printf ("%15.1f  ",mas[j].migracija);
			printf ("%15.1f  ",mas[j].morale);
			printf ("%15d  ",mas[j].bvp);
			printf ("%15.1f  ",mas[j].rastingumas);
			printf ("%15.1f  ",mas[j].telekomunikacijos);
			printf ("%15.1f  ",mas[j].arimas);
			printf ("%15.1f  ",mas[j].augalai);
			printf ("%15.1f  ",mas[j].kita);
			printf ("%15.1f  ",mas[j].klimatas);
			printf ("%15.1f  ",mas[j].gimstamumas);
			printf ("%15.1f  ",mas[j].mirtingumas);
			printf ("%15.1f  ",mas[j].zemdirbyste);
			printf ("%15.1f  ",mas[j].industrija);
			printf ("%15.1f  ",mas[j].paslaugos);
			printf ("\n");
		}	
}
