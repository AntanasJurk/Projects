STEKAS SEGMENT STACK
DB  256 DUP(0)
STEKAS ENDS
DUOMENYS SEGMENT
tekstas DB 'tekstas',10, 13
DB 'tvarkingas', '$'
DUOMENYS ENDS
PROGRAMA SEGMENT
ASSUME CS:PROGRAMA,DS:DUOMENYS,SS:STEKAS
START: 
MOV AX, DUOMENYS
MOV DS, AX
MOV AH, 0		


VALOM_EKRANA:
MOV AX, 0600H
MOV BH, 07
MOV CX, 0000
MOV DX, 184FH
INT 10H
	 
ISVEDAM:
LEA DX, tekstas				
MOV AH, 09h		;teksto isvedimo komanda
INT 21h			;inicializuojam teksto isvedima



BAIGIAM:
MOV AH, 4Ch		;pertraukimo komanda
INT 21h			;inicializuojam petraukimo komanda

	




PROGRAMA ENDS
END START

