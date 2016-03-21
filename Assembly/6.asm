Stekas SEGMENT STACK
DB 256 DUP(?)
Stekas ENDS
Duom SEGMENT

MAS DB 5, 1, 1, 0
	DB 5, 2, 2, 2
	DB 5, 1, 3, 0
	DB 3, 2, 1, 3
	DB 5, 1, 5, 0
	DB 4, 1, 5, 2
	DB 5, 1, 7, 0
REZ DB 7 DUP(0)
ATS db 3 dup(' ')
	db ','
	db 2 dup(' '), '$'
Skip DB 10, 13, '$'
Ten DB 10
Four DB 4
Duom ENDS

Prog SEGMENT
ASSUME DS:Duom, CS:Prog, SS: stekas

EKRANAS PROC
	MOV AX, 0600h	;isvalymas
	MOV BH, 07
	MOV CX, 0000
	MOV DX, 184Fh
	INT 10h
	MOV AH, 02		;kursoriaus nustatymas
	MOV BH, 00
	MOV DL, 0 ; stulp
	MOV DH, 0 ; eilute
	INT 10h
RET
EKRANAS ENDP

CALC PROC
MOV CX, 7
LEA DI, MAS
LEA SI, REZ
	CIKLASOUT:
	PUSH CX
	;pasiruosimas vidiniam ciklui
	MOV CX, 4
		CIKLASIN:
		MOV DH, [DI]
		ADD [SI], DH
		INC DI
		LOOP CIKLASIN
	INC SI
	POP CX
	LOOP CIKLASOUT
RET
CALC ENDP

SPAUS PROC
	LEA DI, Rez
	MOV CX, 7
rezCiklas:
	MOV AH, 0
	MOV AL, [DI]
	DIV Four
	LEA BX, Ats + 2
	PUSH CX
	PUSH AX
	MOV AH, 0	;sveikoji dalis
	MOV CX, 3
	sdCiklas:
		DIV Ten
		ADD AH, 30h
		MOV [BX], AH
		MOV AH, 0
		DEC BX
		loop sdCiklas	
	POP AX	;liekana
	LEA BX, Ats + 4
	mov cx, 2
	liekCiklas:
		mov al, ah
		mul Ten
		div Four
		ADD al, 30h
		MOV [BX], Al
		inc bx
		loop liekCiklas	
	LEA DX, Ats
		MOV AH, 09h ;i ekrana
		INT 21h	
	lea dx, Skip
		MOV AH, 09h ;i ekrana
		INT 21h
	POP CX
	INC DI
	loop rezCiklas
RET
SPAUS ENDP

START:
  CALL EKRANAS
  MOV AX, Duom
  MOV DS, AX
  CALL CALC
  CALL SPAUS
PABAIGA:
MOV AH, 4Ch
INT 21h
Prog ENDS
END START