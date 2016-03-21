#include "Definicijos.h"
#include "Struktura.h"

void esamu_elementu_pakeitimas()
{
	int v;
	int j;
	int q=0;
	float x=0;
	char g[50];
	isvedimas_i_ekrana();
	printf ("\nParinkite norimu keisti atributu eilutes numeri: ");									//Nuskaitomas elementu eilutes numeris
	scanf ("%d",&v);
	system ("cls");
	printf ("Salies pavadinima: \n");scanf ("%s",g);strcpy (mas[v].pav,g);							//Priklausomai nuo numerio, atliekamo to elemento pakeitimai
	printf ("Salies populiacija: \n");scanf ("%d",&q);	mas[v].populiacija=q;q=0;							//Vartotojas pats iveda norimas atributu reiksmes
	printf ("Salies plota: \n");scanf ("%d",&q);	mas[v].plotas=q;q=0;								//Naujos reiksmes irasomos senu vietoje
	printf ("Salies populiacjos tanki: \n");scanf ("%f",&x);	mas[v].poptankis=x;x=0;
	printf ("Kiek salies teritorijos sudaro pakrante: \n");scanf ("%f",&x);	mas[v].pakrante=x;x=0;
	printf ("Migracijos lygis: \n");scanf ("%f",&x);	mas[v].migracija=x;x=0;
	printf ("Morales lygis: \n");scanf ("%f",&x);	mas[v].morale=x;x=0;
	printf ("Salies BVP: \n");scanf ("%d",&q);	mas[v].bvp=q;q=0;
	printf ("Rastingumo lygis: \n");scanf ("%f",&x);	mas[v].rastingumas=x;x=0;
	printf ("Telekomunikacijos lygis: \n");scanf ("%f",&x);	mas[v].telekomunikacijos=x;x=0;
	printf ("Arimo lygis: \n");scanf ("%f",&x);	mas[v].arimas=x;x=0;
	printf ("Augalai: \n");scanf ("%f",&x);	mas[v].augalai=x;x=0;
	printf ("Kita: \n");scanf ("%f",&x);	mas[v].kita=x;x=0;
	printf ("Klimato zona: \n");scanf ("%f",&x);	mas[v].klimatas=x;x=0;
	printf ("Gimstamumas: \n");scanf ("%f",&x);	mas[v].gimstamumas=x;x=0;
	printf ("Gyventoju mirtingumas: \n");scanf ("%f",&x);	mas[v].mirtingumas=x;x=0;
	printf ("Salies zemdirbystes lygis: \n");scanf ("%f",&x);	mas[v].zemdirbyste=x;x=0;
	printf ("Salies industrijos lygis: \n");scanf ("%f",&x);	mas[v].industrija=x;x=0;
	printf ("Salies paslaugu lygis: \n");scanf ("%f",&x);	mas[v].paslaugos=x;x=0;
	isvedimas_i_ekrana();
	system ("pause");
}