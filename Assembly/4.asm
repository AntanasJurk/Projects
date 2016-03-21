STEKAS SEGMENT STACK
DB  256 DUP(?)
STEKAS ENDS
DUOMENYS SEGMENT
IVSR DB 25, 0, 25 DUP(?)
DU DB 2
DUOMENYS ENDS
PROGRAMA SEGMENT
ASSUME CS:PROGRAMA,DS:DUOMENYS,SS:STEKAS
START: MOV AX, DUOMENYS
MOV DS, AX

IVESTIS:
MOV AH, 0Ah
LEA DX, IVSR
INT 21h

APDOROTI:
MOV CX, 0
LEA BX, IVSR+2		;perkeliam ivesto teksto adresa
MOV CL, IVSR+1		;perkeliam simboliu skaiciu
ADD BX,CX
MOV AL, '$'
MOV [BX], AL		;pridedam pabaigos simboli

VALYMAS:
MOV AX, 0600H
MOV BH, 07
MOV CX, 0000
MOV DX, 184FH
INT 10H

KOORD:
MOV AX,80			;surandam centro koordinates
MOV cl,ivsr+1
SUB AX,CX
DIV DU

KURSOR:
MOV AH, 02
MOV BH, 00
MOV DL, AL
MOV DH, 12
INT 10H

ISVESTIS:
MOV AH, 09
LEA DX, IVSR+2
INT 21H

BAIGIAM:
MOV AH, 4ch
INT 21H


PROGRAMA ENDS
END START



