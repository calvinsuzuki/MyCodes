;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; - Fazer um contador BCD de 3 dígitos decimais mostrados em displays de 7 segmentos catodo
; - comum. A contagem deve ser crescente de 000 a 199 voltando a 000. Uma chave ligada na
; - interrupção externa 1 (Int1) sensível a descida de borda para a contagem e se acionada
; - novamente recomeça a contagem do valor que parou.
;*********************************************************************************************
	ORG	0
	SJMP	PROG
;***********************
	ORG	13H
	CPL	20H.0
	RETI
;***********************
PROG:	SETB	EA
	SETB	EX1
	SETB	IT1
	SETB	20H.0
INIC:	MOV	A, #00		; Início do contador
	MOV	R3, #00		; Valor INICIAL do MSB
LOOP:	JNB	20H.0, LOOP
	MOV	R0, A		; CONTADOR SALVO EM R0
	ACALL	CONV2		
	ACALL	DISPLAY7
	MOV 	A, R0		; RECUPERA VALOR DO CONTADOR
	INC	A		; INCREMENTA CONTADOR
	CJNE	A, #0C8H, LOOP	; VERIFICA SE SUPERIOR A 199 EM BCD
	JMP	INIC		; SE AMIOR QUE 199, VOLTA A ZERO

;********************************************************
; Rotina que converte um valor hexa no Acumulador de	*
; 00 a C7h, em BCD de 3 dígitos de 000 a 199		*
; em R3 = MSB, R2 = ISB, R1 = LSB			*
;********************************************************
 CONV2:	CJNE	A, #64H, TESTE
 TESTE:	JC	MENOR
 	SUBB	A, #64H
 	MOV	R3, #1
 	ACALL	CONVBCD
 	RET
 MENOR:	ACALL	CONVBCD
 	RET

;********************************************************
; Rotina que converte um byte em Acc de 00 a 63h em	*
; um número BCD de 00 a 99 no Acumulador		*
; fazendo R1 = LSB e R2 = ISB				*
;********************************************************
CONVBCD:
	MOV	B, #0AH
	DIV	AB
	MOV	R2, A
	MOV	R1, B
	SWAP	A
	ORL	A, R1
	RET
;********************************************************
DISPLAY7:
	MOV	DPTR, #DIGITO
	MOV	A, R1
	MOVC	A, @A+DPTR
	MOV	P0, A
	MOV	A, R2
	MOVC	A, @A+DPTR
	MOV	P2, A
	MOV	A, R3
	MOVC	A, @A+DPTR
	MOV	P1, A
	;ACALL	DELAY
	RET
;********************************************************
DIGITO:	DB	3FH, 06, 5BH, 4FH, 66H, 6DH, 7DH, 07, 7FH, 6FH
;********************************************************
;DELAY:	