Stekas SEGMENT STACK
	DB 256 dup(0)
Stekas ENDS

Duom SEGMENT
mesg1 db "Iveskite skaiciu: $"                            
mesg2 db "Rezultatas: $"
newline db 0dh, 0ah, '$'                                      ;isvedimo buferis 6 baitu ilgio
dec_eilute equ pradzia+6                                   
buffer db 6                 ;ivedimo buferis 6 baitu ilgio                     
bufilgis db ?    
Duom enDS
	
Prog SEGMENT
ASSUME DS:Duom, CS:Prog, SS:Stekas

Ekranas PROC
	
MOV AX, 0600H
MOV BH, 07
MOV CX, 0000
MOV DX, 184FH
INT 10H
RET
Ekranas ENDP

start:
	MOV AX,Duom
	MOV DS, AX
	CALL Ekranas
	
	
	MOV AH, 4ch
	INT 21h
Prog ENDS
END start	
	
	
