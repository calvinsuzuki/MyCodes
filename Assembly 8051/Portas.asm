;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Faça um programa que teste o bit P1.0 da Porta P1. Usando o simulador, ligue uma chave no
; pino P1.0 da CPU.
; Se P1.0 = 0 escrever FFh na posição 1200h da RAM externa, setar o bit P3.0 e zerar o bit
; P3.1
; Se P1.0 = 1 escrever 7Fh na posição 1200h da RAM externa, setar o bit P3.1 e zerar o bit
; P3.0
; Usando o simulador MCU8051, ligar um led em cada um dos pinos da Porta P3 (P3.0 e P3.1)
; para visualização do resultado.

; O programa deve ficar em loop observando o bit P1.0 da porta P1 e atualizando o valor da
; posição 1200h da RAM externa.
;*********************************************************************************************

	ORG	0

	MOV	DPTR, #1200H
LOOP:	JB	P1.0, ESC7F
	MOV	A, #0FFH
	MOVX	@DPTR, A
	SETB 	P3.0
	CLR	P3.1
	SJMP	LOOP

ESC7F:	MOV	A, #07FH
	MOVX	@DPTR, A
	SETB	P3.1
	CLR	P3.0
	SJMP	LOOP

	END
	
	END
