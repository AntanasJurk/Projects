#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <cmath>


using namespace std;

struct VMCommand
{
	char code;				//Kodas
	char cop1;				//Parametras
};


void main()
{

	unsigned char regs[16];					//Registrai							
	int pab = 0;
	int iReg1, iReg2;						//Kintamieji laikinam registo numeriui
	char prog_mem [256];					//Programos atmintis
	VMCommand *r_pc;
			

	ifstream File_Bin; 
	ifstream File_Txt;
	File_Bin.open ("decryptor.bin",ios::binary);
	File_Txt.open ("q1_encr.txt");
	if (!File_Bin) {
        cout<<"Bin failo atidaryti nepavyko"<<endl;
		exit (1);
    }	if (!File_Txt) {
        cout<<"Txt failo atidaryti nepavyko"<<endl;
		exit (1);
    }
	int i=0;
	while (!File_Bin.eof())
	{
		File_Bin.get(prog_mem[i]);
		i++;
	}
	r_pc=(VMCommand*)prog_mem;					//Registru rodykle(nuoroda), rodo i atminties baita (i komanda)

	while (pab==0)
	{	
		iReg1 = r_pc->cop1 & 0x0F;					//Nustatomi laikinieji registru numeriai naudojant & AND operacija (isvalom pirma nari)
		iReg2 = (r_pc->cop1 & 0xF0)>>4;				
		
	
	
		if(r_pc->code==0x03)					//Kopijuoja registrà Ry á Rx
		{
			iReg2=iReg1; 
		}

		else if(r_pc->code==0x04)						//Kopijuoja baito konstantà á registrà R0. 2–o tipo komanda
		{	
			regs[0]=r_pc->cop1;				
		}

		else if(r_pc->code==0x05)					//Registro Rx postûmis á kairæ per 1 bità	(bitshift)
		{
			regs[iReg1]=regs[iReg1]<<1; 
		}

		else if(r_pc->code==0x07)					//Ðuolis santykiniu adresu pridedant konstantà (suþenklu) «addr» prie komandø skaitiklio. Visi ðuoliaiyra 2-o tipo komandos
		{
			r_pc=r_pc+r_pc->cop1;
		}

		else if(r_pc->code==0x10)					//Baitas is txt ir registra
		{
			File_Txt>>regs[iReg1];
		
				if (File_Txt.eof())
				{
					pab=1;
				}
		}

		else if(r_pc->code==0x11)
		{
			cout<<regs[iReg1];							//Isvedam i ekrana
		
		}
	/*	else if(r_pc->code==0x0A)						//Kaip ir 0x07, tik jei yra failo pabaigos poþymis 
		{
		if (pab==1)
			{
				r_pc=r_pc+r_pc->cop1/2; 
			}
		}
		*/
	/*	else if(r_pc->code==0x0B)						//Baigiam darba
		{
			break;
		}
		*/
		else if(r_pc->code==0x0D)						//Atima registro y turiná ið registro x ir palieka rezultatàregistre x
		{
			regs[iReg1]=regs[iReg1]-regs[iReg2]; 
		}

		else if(r_pc->code==0x0E)						//XOR
		{
			regs[iReg1]=regs[iReg2]^regs[iReg1];
		}

		else if(r_pc->code==0x0F)						//OR
		{
			regs[iReg1]=regs[iReg2]|regs[iReg1]; 
		}
		r_pc++;								//Sokinejam per 2 baitus
	}
	cout<<endl;
	File_Bin.close();
	File_Txt.close();
	system ("pause");
}
