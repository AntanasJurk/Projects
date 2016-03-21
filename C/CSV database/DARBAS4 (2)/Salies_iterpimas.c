#include "Definicijos.h"
#include "Struktura.h"
void iterpimas(int *k)
{
	int j;
	int q=0;
	float x=0;
	char g[50];
	*k=*k+1;
	system ("cls");
	printf ("Salies pavadinima: \n");scanf ("%s",g);strcpy (mas[*k].pav,g);								//Strukturinio masyvo gale iterpiamos vartotojo pasirinktos reiksmes
	printf ("Salies populiacija: \n");scanf ("%d",&q);	mas[*k].populiacija=q;q=0;
	printf ("Salies plota: \n");scanf ("%d",&q);	mas[*k].plotas=q;q=0;
	printf ("Salies populiacjos tanki: \n");scanf ("%f",&x);	mas[*k].poptankis=x;x=0;
	printf ("Kiek salies teritorijos sudaro pakrante: \n");scanf ("%f",&x);	mas[*k].pakrante=x;x=0;
	printf ("Migracijos lygis: \n");scanf ("%f",&x);	mas[*k].migracija=x;x=0;
	printf ("Morales lygis: \n");scanf ("%f",&x);	mas[*k].morale=x;x=0;
	printf ("Salies BVP: \n");scanf ("%d",&q);	mas[*k].bvp=q;q=0;
	printf ("Rastingumo lygis: \n");scanf ("%f",&x);	mas[*k].rastingumas=x;x=0;
	printf ("Telekomunikacijos lygis: \n");scanf ("%f",&x);	mas[*k].telekomunikacijos=x;x=0;
	printf ("Arimo lygis: \n");scanf ("%f",&x);	mas[*k].arimas=x;x=0;
	printf ("Augalai: \n");scanf ("%f",&x);	mas[*k].augalai=x;x=0;
	printf ("Kita: \n");scanf ("%f",&x);	mas[*k].kita=x;x=0;
	printf ("Klimato zona: \n");scanf ("%f",&x);	mas[*k].klimatas=x;x=0;
	printf ("Gimstamumas: \n");scanf ("%f",&x);	mas[*k].gimstamumas=x;x=0;
	printf ("Gyventoju mirtingumas: \n");scanf ("%f",&x);	mas[*k].mirtingumas=x;x=0;
	printf ("Salies zemdirbystes lygis: \n");scanf ("%f",&x);	mas[*k].zemdirbyste=x;x=0;
	printf ("Salies industrijos lygis: \n");scanf ("%f",&x);	mas[*k].industrija=x;x=0;
	printf ("Salies paslaugu lygis: \n");scanf ("%f",&x);	mas[*k].paslaugos=x;x=0;
}