;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; - Configure a comunicação serial com 19200 bauds, 8 bits de dados, sem paridade, 1 stop bit
; - Escreva um caractere ASCII diretamente no SBUF R (recepção)
; - Faça RI = 1 para informar ao programa que a recepção ocorreu
; - O cristal do micro deve ser de 11,0592 MHz
; - Sem utilizar a interrupção da interface serial e fazer o seguinte programa:
; -> Teclando G (SBUF = 47h) acende o led ligado em P2.0
; -> Teclando Y (SBUF = 59h) acende o led ligado em P2.4
; -> Teclando R (SBUF = 52h) acende o led ligado em P2.7
; -> Teclando D (SBUF = 44h) (Delete) apaga todos os leds e recomeça o programa
;*********************************************************************************************
	ORG	0
	MOV	TMOD, #20H	; Timer 1 em auto-reload
	MOV	SCON, #50H	; Configura SM1 = 1 e RCON = 1
	MOV	TL1, #253
	MOV	TH1, #253
	MOV	PCON, #80H
	SETB	TR1
RESET:	MOV	P2, #0FFH
LOOP:	ACALL	RSERIAL
	CJNE	A, #47H, CONT
	CLR	P2.0
	SJMP	LOOP
CONT:	CJNE	A, #59H, CONT1
	CLR	P2.4
	SJMP	LOOP
CONT1:	CJNE	A, #52H, CONT2
	CLR	P2.7
	SJMP	LOOP
CONT2:	CJNE	A, #44H, LOOP
	SJMP	RESET
;******************************************
RSERIAL:JNB	RI, $
	MOV	A, SBUF
	CLR	RI
	RET
