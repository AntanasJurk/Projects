#include "Definicijos.h"
#include "Prototipai.h"
void issiuntimas (int *k)
{
	int i,c=1;
	while (c>=1)
		{
		c=0;
		pasirinkimas(&i);
		switch(i)											//Pagal vartojo pasirinkima, vykdoma atitinkama operacija
		{
		case (1):
			{	
				isvedimas_i_ekrana();
				uzklausa2(&c);
				break;
			}
		case (2):
			{
				paieskos_uzklausa();
				uzklausa2(&c);
				break;
			}
		case (3):
			{
				iterpimas(k);
				uzklausa2(&c);
				break;
			}
		case (4):
			{
				esamu_elementu_pakeitimas();
				uzklausa2(&c);
				break;
			}
		case (5):
			{
				vidurkis(k);					
				uzklausa2(&c);
				break;
			}
		case (6):
			{
				elementu_sudetis(k);
				uzklausa2(&c);
				break;
			}
		case (8):
			{
				isvedimas();
				uzklausa2(&c);
				break;
			}
		case (7):
			{
				didziausia_reiksme(k);
				uzklausa2(&c);
				break;
			}
		case (9):
			{

				exit(1);
				break;
			}
		default:
			{
				printf ("Blogai ivsetas pasirinkimas");					
				break;
			}
		}
	}
}
void pasirinkimas(int *i)
{
	system("cls");
	printf ("Pasrinkite viena is zemiau pateiktu pasirinkimu \n");			//Pateikiamas operaciju asortimentas
	printf ("1.Pateikti ekrane\n");
	printf ("2.Salies paieska\n");
	printf ("3.Salies iterpimas\n");
	printf ("4.Elemento pakeitimas\n");
	printf ("5.Rasti elementu vidurki\n");
	printf ("6.Rasti elementu suma\n");
	printf ("7.Didziausios reiksmes suradimas\n");
	printf ("8.Isvedimas i faila\n");
	printf ("9.Baigti darba\n");
	printf ("\n");
	printf ("Jusu pasirinkimas:");
	scanf ("%d",&(*i));														//Nuskaitomas vartotojo pasirinkimas
	
}
void uzklausa2(int *c)
{
	int k;
	printf ("\nAr norite pasirinkti kita operacija?\n\n");				//Klausiama, ar vartotojas nori testi darba su programa
	printf ("Jei taip iveskite 1, jei ne 0\n");
	scanf ("%d",&k);
	if (k>=1)
	{
		*c=k;
	}
	else 
	{
		*c=0;
	}
}