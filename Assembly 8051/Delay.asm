;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Utilizando rotinas de atraso, fazer um programa em Assembly que gere uma onda
; quadrada com saídas complementares nos bits P2.0 e P2.1 do Port P2, com período
; aproximado de 100 microssegundos. Observar com leds e com o tempo do simulador
; durante a execução.
;*********************************************************************************************

	ORG	0
LOOP:	MOV	P2, #00000001B
	ACALL	DELAY_50
	MOV	P2, #00000010B
	ACALL	DELAY_50
	SJMP	LOOP
	
DELAY_50:
; START: Wait loop, time: 46 us
; Clock: 12000.0 kHz (12 / MC)
; Used registers: R0
	MOV	R0, #014h
	NOP
	DJNZ	R0, $
; Rest: 0
; END: Wait loop
	RET

	END