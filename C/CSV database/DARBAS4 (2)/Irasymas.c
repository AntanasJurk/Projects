#include "Definicijos.h"
#include "Struktura.h"
#include "Prototipai.h"
void failo_atidarymas(int *k,char (*pavad)[st][max])
{
	FILE *A;																
	A=fopen ("CSV.csv","r");			//Atidaromas CSV failas
	tikrinimas(A);						//Tikrinama, ar pavyko atidaryti CSV faila
	irasymas_i_strukturini_masyva (A,k);
	//pavadinimai(A,pavad);
	fclose(A);	
}
void tikrinimas (FILE *A)
{
	if (A==NULL)															//Tikrinama, ar pavyko atidaryti faila
		{
			printf ("Failo atidartyti nepavyko");
			system ("pause");
			exit(0);														//Neatidarius failo programa baigia darba
		}
}
void irasymas_i_strukturini_masyva (FILE *A, int *k)
{
	char eil[max];															//Sukuriamas trumpalaikis masyvas
	int i=*k,j;
	while (fgets(eil,max,A)!=NULL)											//Nuskaitoma eilute 
	{
	strcpy (mas[i].pav,strtok(eil,";"));									//Atskiriami elementai iki " ; " ir irasomi i strukturos masyva
	mas[i].populiacija=atoi(strtok(NULL,";"));
	mas[i].plotas=atof(strtok(NULL,";"));
	mas[i].poptankis=atof(strtok(NULL,";"));
	mas[i].pakrante=atof(strtok(NULL,";"));
	mas[i].migracija=atof(strtok(NULL,";"));
	mas[i].morale=atof(strtok(NULL,";"));
	mas[i].bvp=atoi(strtok(NULL,";"));
	mas[i].rastingumas=atof(strtok(NULL,";"));
	mas[i].telekomunikacijos=atof(strtok(NULL,";"));
	mas[i].arimas=atof(strtok(NULL,";"));
	mas[i].augalai=atof(strtok(NULL,";"));
	mas[i].kita=atof(strtok(NULL,";"));
	mas[i].klimatas=atof(strtok(NULL,";"));
	mas[i].gimstamumas=atof(strtok(NULL,";"));
	mas[i].mirtingumas=atof(strtok(NULL,";"));
	mas[i].zemdirbyste=atof(strtok(NULL,";"));
	mas[i].industrija=atof(strtok(NULL,";"));
	mas[i].paslaugos=atof(strtok(NULL,";"));
	i++;
	} 
	*k=i;
}
/*void pavadinimai(FILE *A,char (*pavad)[st][max])
{
	int i=1,j;
	char buffer[700],*tok;
	fgets(buffer,700, A);				
	tok = strtok(buffer, ";");			
	strcpy((*pavad)[0], tok);		
	while (i < st)
	{
		tok = strtok(NULL, ";");		
		strcpy((*pavad)[i], tok);
		printf ("%s\n",(*pavad)[i]);
		i++;
	}
	system ("pause");
}*/
void pavad ()
{
printf ("Pavadinimas\t\t\t    Populiacija\t\tPlotas\t\tPop.Tankis\t  Pakrante\t\t  Migracija\t");
printf ("    Morale\t\tBVP\t    Rastingumas\t\tTelekom.\tArimas\t\t Augalai\t\t    Kita");
printf ("\t   Klimatas\t Gimstamumas\t  Mirtingumas\t    Zemdirbyste\t\tIndustrija\t  Paslaugos\n");
}