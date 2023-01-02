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
PROG:	SETB	20H.0
INIC:	MOV	A, #00		; Início do contador
LOOP:	MOV	20H, A		; CONTADOR SALVO EM 20H
	ACALL	CONVBCD		
	ACALL	DISPLAY7
	MOV 	A, 20H		; RECUPERA VALOR DO CONTADOR
	INC	A		; INCREMENTA CONTADOR
	CJNE	A, #064H, LOOP	; VERIFICA SE SUPERIOR A 63 EM BCD
	JMP	INIC		; SE MAIOR QUE 63, VOLTA A ZERO
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
	MOV	P1, A
	ACALL	DELAY
	RET
;********************************************************
DIGITO:	DB	3FH, 06, 5BH, 4FH, 66H, 6DH, 7DH, 07, 7FH, 6FH
;********************************************************
DELAY:	MOV	R0, #006h	; COLOCA TRANSMISSAO AO MONITOR PARA 4800 BPS
	DJNZ	R0, $
	RET
        END