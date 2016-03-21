#include "Definicijos.h"
#include "Struktura.h"
void didziausia_reiksme (int *k)
{
	int m,i,j=0,t=0;															
	float t1=0;
	system ("CLS");
	atributai_be_pavad();
	printf ("Pasirinkite atributo numeri, kurio vidurki noretumete suskaiciuoti: ");				//Nuskaitomas vartotojo pasirinkimas 
	scanf ("%d",&m);
	if (m==1)								//Didziausios reiksmes paieska atliekama is pasirinkto atributo reiksmiu
	{
		t=mas[1].populiacija;				//Priskiriama pirmoji reiksme
		for (i=0;i<*k;i++)					
		{	
			if(mas[i].populiacija>t)		//Tikrinama, ar sekanti reiksme didesne uz pries tai buvusia 
			{
				t=mas[i].populiacija;		//Dedesne reiksme priskiriama kintamajam
				j++;
			}
		}
	}
	if (m==2){t=mas[1].plotas;				for (i=0;i<*k;i++)	{	if(mas[i].plotas>t){t=mas[i].plotas;j++;}}}			
	if (m==3){t1=mas[1].poptankis;			for (i=0;i<*k;i++)	{	if(mas[i].poptankis>t1){t1=mas[i].poptankis;j++;}}}
	if (m==4){t1=mas[1].pakrante;			for (i=0;i<*k;i++)	{	if(mas[i].pakrante>t1){t1=mas[i].pakrante;j++;}}}
	if (m==5){t1=mas[1].migracija;			for (i=0;i<*k;i++)	{	if(mas[i].poptankis>t1){t1=mas[i].migracija;j++;}}}
	if (m==6){t1=mas[1].morale;				for (i=0;i<*k;i++)	{	if(mas[i].poptankis>t1){t1=mas[i].morale;j++;}}}
	if (m==7){t=mas[1].bvp;					for (i=0;i<*k;i++)	{	if(mas[i].bvp>t){t=mas[i].populiacija;j++;}}}
	if (m==8){t1=mas[1].rastingumas;		for (i=0;i<*k;i++)	{	if(mas[i].rastingumas>t1){t1=mas[i].rastingumas;}}}
	if (m==9){t1=mas[1].telekomunikacijos;	for (i=0;i<*k;i++)	{	if(mas[i].telekomunikacijos>t1){t1=mas[i].telekomunikacijos;j++;}}}
	if (m==10){t1=mas[1].arimas;			for (i=0;i<*k;i++)	{	if(mas[i].arimas>t1){t1=mas[i].arimas;j++;}}}
	if (m==11){t1=mas[1].augalai;			for (i=0;i<*k;i++)	{	if(mas[i].augalai>t1){t1=mas[i].augalai;j++;}}}
	if (m==12){t1=mas[1].kita;				for (i=0;i<*k;i++)	{	if(mas[i].kita>t1){t1=mas[i].kita;j++;}}}
	if (m==13){t1=mas[1].klimatas;			for (i=0;i<*k;i++)	{	if(mas[i].klimatas>t1){t1=mas[i].klimatas;j++;}}}
	if (m==14){t1=mas[1].gimstamumas;		for (i=0;i<*k;i++)	{	if(mas[i].gimstamumas>t1){t1=mas[i].gimstamumas;j++;}}}
	if (m==15){t1=mas[1].mirtingumas;		for (i=0;i<*k;i++)	{	if(mas[i].mirtingumas>t1){t1=mas[i].mirtingumas;j++;}}}
	if (m==16){t1=mas[1].zemdirbyste;		for (i=0;i<*k;i++)	{	if(mas[i].zemdirbyste>t1){t1=mas[i].zemdirbyste;j++;}}}
	if (m==17){t1=mas[1].industrija;		for (i=0;i<*k;i++)	{	if(mas[i].industrija>t1){t1=mas[i].industrija;j++;}}}
	if (m==18){t1=mas[1].paslaugos;			for (i=0;i<*k;i++)	{	if(mas[i].paslaugos>t1){t1=mas[i].paslaugos;j++;}}}
	if (m==1||m==2||m==7)						
	{
		printf ("%s",mas[j].pav);				//Isspausdinamas atsakymas priklausomai nuo kintamojo tipo
		printf ("%d\n\n",t);
	}
	else 
	{
		printf ("%s",mas[j].pav);
		printf ("%.2f\n\n",t1);
	}
}