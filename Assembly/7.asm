STEKAS SEGMENT STACK
DB  256 DUP(?)
STEKAS ENDS
DUOMENYS SEGMENT

message db "Sk: $", 10, 13
message3 db " - $"
message4 db " = $"
message6 db " * $"
message7 db " Jusu atsakyas: ( $"
message8 db " ) $"
DUOMENYS ENDS
PROGRAMA SEGMENT
ASSUME CS:PROGRAMA,DS:DUOMENYS,SS:STEKAS
START: 
MOV AX, DUOMENYS
MOV DS, AX
pradzia proc

VALYMAS:
MOV AX, 0600H
MOV BH, 07
MOV CX, 0000
MOV DX, 184FH
INT 10H

PIRMAS:


mov ax, seg message
mov ds, ax
mov dx, offset message
mov ah, 9h
int 21H

mov ah, 1h		;skaito chara (stored in al)
int 21h

PUSH AX


ANTRAS:
mov ax, seg message
mov ds, ax
mov dx, offset message
mov ah, 9h
int 21H

mov ah, 1h		;skaito chara (i al)
int 21h

mov bl, al		;perkeliam pirma simboli i cl

TRECIAS:
mov ax, seg message
mov ds, ax
mov dx, offset message
mov ah, 9h
int 21H

mov ah, 1h		;skaito chara (i al)
int 21h
mov cl, al		;perkeliam pirma simboli i bl


FORMULE:
mov ax, seg message7
mov ds, ax
mov dx, offset message7
mov ah, 9h
int 21H

POP AX
mov dl, al		;Isvedam chara
mov ah, 2h
int 21h
PUSH AX

mov ax, seg message3
mov ds, ax
mov dx, offset message3
mov ah, 9h
int 21H


mov dl, bl		;Isvedam chara
mov ah, 2h
int 21h

mov ax, seg message8
mov ds, ax
mov dx, offset message8
mov ah, 9h
int 21H

mov ax, seg message6
mov ds, ax
mov dx, offset message6
mov ah, 9h
int 21H


mov dl, cl		;Isvedam chara
mov ah, 2h
int 21h


mov ax, seg message4
mov ds, ax
mov dx, offset message4
mov ah, 9h
int 21H


SKAICIAVIMAS:
POP AX
sub al, 30h			;keiciam tipa
sub bl, 30h
sub cl, 30h
sub al, bl
MUL cl
add al, 30h 		;keiciam tipa

ISVEDIMAS:
mov dl, al		;Isvedam chara
mov ah, 2h
int 21h

pradzia endp



MOV AH, 4CH
INT 21H
PROGRAMA ENDS
END START
