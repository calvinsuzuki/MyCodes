;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
;  - O operador deve digitar a senha 7AB3 no teclado matricial. O último caractere deve ser o #
; que informa ao programa que os quatro dígitos anteriores formam a senha.
;  - Se a senha estiver correta, os leds acendem um led por vez iniciando do LSB até MSB.
;  - Caso a senha esteja errada o programa deve piscar todos os leds alternadamente (delay)
;  - Para destravar a maquina, acionar a interrupção externa Int1 sensível a descida de borda,
; que permite realizar nova tentativa de ligar a máquina usando-se a senha correta no teclado matricial
;*********************************************************************************************
	ORG	0
	SJMP	PROG
;*************************************
	ORG	0013H
	SJMP	EXT_1 ; INT1 (P3.3)
;*************************************
PROG:	SETB	EA
	SETB	EX1
	SETB	TR1
	ACALL	SBUFF
	MOV	P2, #0FFH	; APAGA TODOS OS LEDS
INI:	MOV	P1, #0FFH
	MOV	R0, #7FH
LOOP:	ACALL	VARRE
	MOV	A, P1
	ORL	A, #0F0H
	CJNE	A, #0FFH, TECLA
	SJMP	LOOP
TECLA:	MOV	A, P1
	CJNE	A, 20H, NEW_KEY	; DETECTA MUDANCA DE TECLA
	SJMP	INI

NEW_KEY:
	MOV	20H, A
	CJNE	A, #0B7H, SAVE	; LEITURA #
	;	VERIFICA ULTIMOS 4 DIGITOS (SENHA: EB 7E 7D BE)
	MOV	A, 21H
	CJNE	A, #0EBH, FAIL
	MOV	A, 22H
	CJNE	A, #07EH, FAIL
	MOV	A, 23H
	CJNE	A, #07DH, FAIL
	MOV	A, 24H
	CJNE	A, #0BEH, FAIL
;	CASO SENHA CORRETA
	MOV	A, #0FEH
WELCOME:RL	A
	MOV	P2, A
	SJMP	WELCOME
SAVE:	CJNE	R1, #25H, FILL
	SJMP	INI
FILL:	MOV	@R1, A
	INC	R1
	SJMP	INI
;	CASO SENHA INCORRETA
FAIL:	ACALL	FALHA
	SJMP	INI
;*************************************
EXT_1:	SETB	20H.0
	RETI
;*************************************
VARRE:	MOV	A, R0
	MOV	P1, A
	RR	A
	JNB	A.3, FIM
	MOV	R0, A
	RET
FIM:	MOV	R0, #7FH
	RET
;*************************************
SBUFF:	MOV	R1, #21H
	MOV	21H, #0H
	MOV	22H, #0H
	MOV	23H, #0H
	MOV	24H, #0H
	RET
;*************************************
DELAY:	MOV	R0, #00Bh
	DJNZ	R0, $
	RET
;*************************************
;	CASO SENHA INCORRETA
FALHA:	CLR	20H.0
LOOP0:	MOV	P2, #0H
	ACALL	DELAY
	MOV	P2, #0FFH
	ACALL	DELAY
	JNB	20H.0, LOOP0
	ACALL	SBUFF
	RET
;*************************************
	END
