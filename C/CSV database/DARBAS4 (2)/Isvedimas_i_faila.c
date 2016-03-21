#include "Definicijos.h"
#include "Struktura.h"
void isvedimas ()
{
	FILE *B;
	int i;
	B=fopen("CSV.csv","w");			//Atidaromas CSV failas, tik si karta rasymui
    tikrinimas (B);					//Tikriname ar pavykto atidaryti CSV faila
    for (i=1;i<103;i++)				//Irasome reiksmes is strukturos masyvo i CSV faila
    {
        fprintf(B,"%s;",mas[i].pav);										
		fprintf(B,"%d;",mas[i].populiacija);	
		fprintf(B,"%d;",mas[i].plotas);
		fprintf(B,"%.1f;",mas[i].poptankis);
		fprintf(B,"%.1f;",mas[i].pakrante);
		fprintf(B,"%.1f;",mas[i].migracija);
		fprintf(B,"%.1f;",mas[i].morale);
		fprintf(B,"%.d;",mas[i].bvp);
		fprintf(B,"%.1f;",mas[i].rastingumas);
		fprintf(B,"%.1f;",mas[i].telekomunikacijos);
		fprintf(B,"%.1f;",mas[i].arimas);	
		fprintf(B,"%.1f;",mas[i].augalai);	
		fprintf(B,"%.1f;",mas[i].kita);
		fprintf(B,"%.1f;",mas[i].klimatas);
		fprintf(B,"%.1f;",mas[i].gimstamumas);
		fprintf(B,"%.1f;",mas[i].mirtingumas);
		fprintf(B,"%.1f;",mas[i].zemdirbyste);
		fprintf(B,"%.1f;",mas[i].industrija);
		fprintf(B,"%.1f\n",mas[i].paslaugos);
    }
    fclose(B);						//Faila zudaromas
}