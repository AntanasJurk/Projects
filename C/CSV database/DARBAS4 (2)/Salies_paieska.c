#include "Definicijos.h"
#include "Struktura.h"
#include "Prototipai.h"
void paieskos_uzklausa ()
{
	int l;
	system("cls");
	printf ("Iveskite atributo numeri, pagal kuri atributa bus atliekama paieska?\n");		//Pasirinkimas, kuriuo atributu bus ieskoma salis
	printf (" 1. Pavadinima\n");
	printf (" 2. Populiacija\n");
	printf (" 3. Plota\n");
	printf (" 4. Populiacijos tanki\n");
	printf (" 5. Pakrante\n");
	printf (" 6. Migracija\n");
	printf (" 7. Kudykiu morale\n");
	printf (" 8. BVP\n");
	printf (" 9. Rastingumas\n");
	printf ("10. Telekomunikacijos\n");
	printf ("11. Arimas\n");
	printf ("12. Aygalai\n");
	printf ("13. Kita\n");
	printf ("14. Klimato zona\n");
	printf ("15. Gimstamumas\n");
	printf ("16. Mirtingumas\n");
	printf ("17. Zemdirbyste\n");
	printf ("18. Industrija\n");
	printf ("19. Paslaugos\n"); 
	scanf ("%d",&l);
	atributo_ivedimas(l);
}
void atributo_ivedimas (int l)
{
		
	int h;
	float p;
	char g[50];
	if ((l==2)||(l==3)||(l==8))										//Nuskaito int tipo pasirinkima
	{
		printf ("Iveskite atributo reiksme: ");
		scanf ("%d",&(h));
	}
	else if (l==1)													//Nuskaito char tipo pasirinkima
	{
		printf ("Iveskite salies pavadinima: ");
		scanf ("%s",&g);		
	}
	else															//Nuskaito float tipo pasirinkima
	{
		printf ("Iveskite atributo reiksme: ");
		scanf ("%f",&(p));
	}
	atitikmens_radimas(l,&h,&p,&g);
}
void atitikmens_radimas(int l, int *h, float *p, char (*g)[50])
{
	int j,i=0;
	for (j=1;j<101;j++)												
	{
		if(strcmp (mas[j].pav,*g) == 1){isvedimas_be_ciklo(j);i++;}				//Ieskoma, ar ivestas atributas atitinka jau esanti tos rusies atributa
		if (mas[j].populiacija==(*h)){isvedimas_be_ciklo(j);}							//Suradus atitikmeni, vykdomas isvedimas
		if (mas[j].plotas==(*h)){isvedimas_be_ciklo(j);}
		if (mas[j].poptankis==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].pakrante==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].migracija==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].morale==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].bvp==(*h)){isvedimas_be_ciklo(j);}
		if (mas[j].rastingumas==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].telekomunikacijos==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].arimas==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].augalai==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].kita==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].klimatas==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].gimstamumas==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].mirtingumas==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].zemdirbyste==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].industrija==(*p)){isvedimas_be_ciklo(j);}
		if (mas[j].paslaugos==(*p)){isvedimas_be_ciklo(j);}
		if (i!=0)
		{break;}
	}
}
void isvedimas_be_ciklo(int j)
{
	
	int c=0;	
	pavad ();
	printf ("%-25s  ",mas[j].pav);							//Isvedama visas salies informacija, kurios atributu buvo vykdoma paieska
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