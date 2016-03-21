#include "Definicijos.h"
#include "Struktura.h"

void vidurkis(int *k)
{
	int m,i,t=0,l=0;
	float t1=0,l1=0;
	system ("CLS");																					//Pateikiami atributai pasirinkimui
	atributai_be_pavad();
	printf ("Pasirinkite atributo numeri, kurio vidurki noretumete suskaiciuoti: ");				//Nuskaitomas vartotojo pasirinkimas 
	scanf ("%d",&m);
	if (m==1){	for (i=0;i<*k;i++)	{	t=mas[i].populiacija;l=l+t;t=0;		}}								//Surandami pasirinkti atributai ir suskaiciuojama ju suma
	if (m==2){	for (i=0;i<*k;i++)	{	t=mas[i].plotas;l=l+t;t=0;	}}
	if (m==3){	for (i=0;i<*k;i++)	{	t1=mas[i].poptankis;l1=l1+t1;t1=0;	}}
	if (m==4){	for (i=0;i<*k;i++)	{	t1=mas[i].migracija;l1=l1+t1;t1=0;	}}
	if (m==5){	for (i=0;i<*k;i++)	{	t1=mas[i].morale;l1=l1+t1;t1=0;	}}
	if (m==6){	for (i=0;i<*k;i++)	{	t=mas[i].bvp;l=l+t;t=0;		}}
	if (m==7){	for (i=0;i<*k;i++)	{	t1=mas[i].rastingumas;l1=l1+t1;t1=0;	}}
	if (m==8){	for (i=0;i<*k;i++)	{	t1=mas[i].telekomunikacijos;l1=l1+t1;t1=0;	}}
	if (m==9){	for (i=0;i<*k;i++)	{	t1=mas[i].arimas;l1=l1+t1;t1=0;	}}
	if (m==10){	for (i=0;i<*k;i++)	{	t1=mas[i].augalai;l1=l1+t1;t1=0;	}}
	if (m==11){	for (i=0;i<*k;i++)	{	t1=mas[i].kita;l1=l1+t1;t1=0;	}}
	if (m==12){	for (i=0;i<*k;i++)	{	t1=mas[i].klimatas;l1=l1+t1;t1=0;	}}
	if (m==13){	for (i=0;i<*k;i++)	{	t1=mas[i].gimstamumas;l1=l1+t1;t1=0;	}}
	if (m==14){	for (i=0;i<*k;i++)	{	t1=mas[i].mirtingumas;l1=l1+t1;t1=0;	}}
	if (m==15){	for (i=0;i<*k;i++)	{	t1=mas[i].zemdirbyste;l1=l1+t1;t1=0;	}}
	if (m==16){	for (i=0;i<*k;i++)	{	t1=mas[i].industrija;l1=l1+t1;t1=0;	}}
	if (m==17){	for (i=0;i<*k;i++)	{	t1=mas[i].paslaugos;l1=l1+t1;t1=0;	}}
	if (m==1||m==2||m==6)
	{
		int vid=l/(*k);															//Suskaiciuojamas vidurkis ir isspausdinamas atsakymas, priklausomai nuo kintamojo tipo
		printf ("%d\n\n",vid);
	}
	else 
	{
		float vid2=l1/(*k);
		printf ("%.2f\n\n",vid2);
	}
}