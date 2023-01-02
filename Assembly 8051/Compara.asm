;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Faça um programa que compare dois dados armazenados na memória de programa do 8051
; (colocar logo depois da última instrução usando DB), armazenando o menor deles na posição
; 1200H da RAM externa.
;*********************************************************************************************

	ORG	0
	CLR	A
	MOV	DPTR, #XPTR	; DPTR == 0A3H 
	MOVC	A, @A+DPTR	; 'MOV' NAO PODE SER USADO NA MEM EXTERNA!!!
	MOV	30H, A

	INC	DPTR
	CLR	A
	MOVC	A, @A+DPTR	; DPTR == 3AH
	
	
	CJNE	A, 30H, JUMP
JUMP:	JC	MENOR
MAIOR:	MOV	A, 30H
MENOR:	MOV	DPTR, #1200H

	MOVX	@DPTR, A

	SJMP	$

XPTR:	DB 0A3H, 3AH
	
	END