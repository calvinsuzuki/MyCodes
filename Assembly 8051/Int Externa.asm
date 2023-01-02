;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Utilizando rotinas de atraso, escrever um programa em Assembly que gere duas ondas
; quadradas: uma com frequência de aproximadamente 10 kHz e outra com frequência de
; aproximadamente 20 kHz. Uma solicitação de interrupção externa 0 (Int0 - sensível a
; descida de borda) altera entre as duas frequências, enviando o sinal para a saída P2.2 o
; que piscará o Led na frequência determinada. O programa deve ficar em loop infinito
; alternando as frequências a cada solicitação de interrupção. Inserir uma chave para
; acionar a interrupção via Simple Keypad
;*********************************************************************************************
	ORG	0
	SJMP	PROG
;******************************************
	ORG	3
	SJMP	EXT_0
;******************************************
PROG:	ACALL	VAR_SET	;	ARRUMA AS VARIAVEIS
LOOP:	JNB	P2.0, FREQ10
	JB	P2.0, FREQ20
	SJMP	LOOP
;******************************************
EXT_0:	CLR	EA
	CPL	P2.0
	SETB	EA
	RETI
;******************************************
FREQ10:	MOV	R0, #018h
	DJNZ	R0, $
	CPL	P2.2
	SJMP	LOOP
;******************************************
FREQ20:	MOV	R0, #00Bh
	DJNZ	R0, $
	CPL	P2.2
	SJMP	LOOP
;******************************************
VAR_SET:SETB	EA
	SETB	EX0
	SETB	IT0	; DESCIDA DE BORDA
	RET
;******************************************
	END