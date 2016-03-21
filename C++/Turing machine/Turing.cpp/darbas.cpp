#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
using namespace std;

#define max 500
void pasirinkimas();

struct str
{
	string bus1;
	char sym1;
	char sym2;
	char kryp;
	string bus2;
};
struct str mas[max];

void main (int argc, char *argv[ ])
{
	int b,pr,a=0,z=0,kiek,kom;
	string st="0";
	char A[77];
	ifstream fd;
	cout<<"1.add_bin.tmprog"<<endl;
	cout<<"2.increment_dec.tmprog"<<endl;
	cout<<"3.running_ones.tmprog"<<endl;
	cout<<"4.TURING_increment_bin.tmprog"<<endl;
	cin>>b;

	if (b==1){fd.open ("add_bin.tmprog.txt");kiek=77;kom=65;fd>>pr;} 
	else if (b==2){fd.open ("increment_dec.tmprog.txt");kiek=28;kom=21;fd>>pr;}
	else if (b==3){fd.open ("running_ones.tmprog.txt");kiek=48;kom=16;fd>>pr;}
	else if (b==4){fd.open ("TURING_increment_bin.tmprog.txt");kiek=28;kom=5;fd>>pr;}

	if (!fd)									//Tikrinam ar pavyko atidaryti faila
    {
        cout << "Nepavyko"<<endl;
		exit (1);
    }


	for (int h=0;h<kiek;h++)						//I masyva irasom ilgaja eilute
	{
		fd>>A[h];
	}
	for (int i=0;i<kom;i++)						//I masyva irasome operaciju komandas
	{
		fd>>mas[i].bus1;
		fd>>mas[i].sym1;
		fd>>mas[i].sym2;
		fd>>mas[i].kryp;
		fd>>mas[i].bus2;
	}
	cout<<endl;
	//for (int j=0;j<300;j++)
	while (pr>-1 || st!="X")
	{
		if ((mas[a].bus1==st)&&(mas[a].sym1==A[pr]))		//Tikrinama busena ir esantis elementas
		{
		
		//	cout<<"Sk "<<;
			A[pr]=mas[a].sym2;								//Atliekami atitinkmai pakeitimai
			st=mas[a].bus2;
			if (mas[a].kryp=='R')
			{
				pr++;
				a=0;
			}
			else 
			{
				pr--;
				a=0;
			}
		}
		else 
		{
			a++;
		}
		for (int h=0;h<kiek;h++)
		{
			cout <<A[h];
		}
		cout<<"\n";
		//system ("CLS");
	}
	fd.close();
	system ("pause");
}