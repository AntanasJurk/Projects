STEKAS SEGMENT STACK
DB  256 DUP(?)
STEKAS ENDS
DUOMENYS SEGMENT
T DB 'sanatnA*'
ATV DB 8 DUP (' ')
DUOMENYS ENDS
PROGRAMA SEGMENT
ASSUME CS:PROGRAMA,DS:DUOMENYS,SS:STEKAS
START: MOV AX, DUOMENYS
MOV DS, AX

VALOM_EKRANA:
MOV AX, 0600H
MOV BH, 07
MOV CX, 0000
MOV DX, 184FH
INT 10H

PRADEDAM:
MOV CX, 0
LEA BX, T
LEA SI, ATV+7

CIKLAS: 
MOV AH, [BX]		;Apverciam teksta
MOV [SI], AH
INC BX
DEC SI
LOOP CIKLAS

MOV AH, '$'			;Idedam pabaigos simboli
MOV ATV+8, AH

MOV AH, 09
LEA DX, ATV
INT 21h


MOV AH, 4ch
INT 21h
PROGRAMA ENDS
END START