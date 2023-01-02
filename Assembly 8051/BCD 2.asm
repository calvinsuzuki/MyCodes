;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; - Fazer um contador BCD de 3 dígitos decimais mostrados em displays de 7 segmentos catodo
; - comum. A contagem deve ser crescente de 000 a 199 voltando a 000. Uma chave ligada na
; - interrupção externa 1 (Int1) sensível a descida de borda para a contagem e se acionada
; - novamente recomeça a contagem do valor que parou.
; - Agora para um display multiplexado
;*********************************************************************************************
	ORG	0
	SJMP	PROG
;*************************************
	ORG	13H
	CPL	20H.0
	RETI
;*************************************
PROG:	SETB	EA
	SETB	EX1
	SETB	IT1
	SETB	20H.0
	MOV	P2, #00		; APAGA OS DISPLAYS
	MOV	P1, #00		; APAGA OS SEGMENTOS
	MOV	R7, #80H	; R7 É SELEÇÃO DO DISPLAY (INICIO = 10000000)
	MOV	31H, #0H	; D1 = DÍGITO MAIS À DIREITA (INICIO DO BUFFER DOS DISPLAYS)
	MOV	32H, #0H	; D2 = SEGUNDO DÍGITO
	MOV	33H, #0H	; D3 = TERCEIRO DÍGITO
	MOV	34H, #0H	; D4 = DÍGITO À ESQUERDA (FIM DO BUFFER)
	MOV	DPTR, #DIGITO	; PONTEIRO DOS VALORES EM 7 SEGMENTOS
LOOP:	MOV	R1, #31H	; PONTEIRO INICIAL DO BUFFER DOS DISPLAYS
LOOP2:	CJNE	R1, #31H, SHOW
	ACALL	CONT200
SHOW:	MOV	A, @R1
	ANL	A, #0FH		; SEPARA SOMENTE O DÍGITO MENOS SIGNIFICATIVO
	MOVC	A, @A+DPTR	; ACC CONTÉM CÓDIGO 7 SEGMENTOS
	MOV	P2, #00		; APAGA DISPLAY
	ACALL	MOSTRA
	SJMP	LOOP2 
;********************************************************
; SUBROTINA QUE FAZ A CONTAGEM ATÉ 200 EM 3 ENDEREÇOS	*
; NA ORDEM D1=31H, D2=32H, D3=33H			*
;********************************************************
CONT200:
	JNB	20H.0, ENDCONT
	INC	31H
	MOV	R0, 31H
	CJNE	R0, #10D, END200
	MOV	31H, #0D
	INC	32H
	MOV	R0, 32H
	CJNE	R0, #10D, END200
	MOV	32H, #0D
	INC	33H
	MOV	R0, 33H
	CJNE	R0, #10D, END200
END200:	MOV	R0, 31H
	CJNE	R0, #0D, ENDCONT
	MOV	R0, 32H
	CJNE	R0, #0D, ENDCONT
	MOV	R0, 33H
	CJNE	R0, #2D, ENDCONT
	MOV	31H, #00
	MOV	32H, #00
	MOV	33H, #00
ENDCONT:RET
;********************************************************
; SUBROTINA QUE ENVIA O CONTEÚDO DO BUFFER DOS DISPLAYS	*
; NA ORDEM D1=31H, D2=32H, D3=33H, D4=34H		*
;********************************************************
MOSTRA:	MOV	P1, A		; ENVIA CODIGO 7 SEGMENTOS
	MOV	A, R7		; RECUPERA POSIÇÃO ATUAL DO DISPLAY
	RL	A		; ATUALIZA POSIÇÃO DO DISPLAY A SER UTILIZADO
	JB	ACC.4, FIM	; TESTA SE POSIÇÃO ATUAL É O QUINTO DISPLAY
	MOV	P2, A		; ACENDE O DISPLAY NA POSIÇÃO DEFINIDA
	MOV	R7, A		; SALVA A POSIÇÃO ATUAL
	INC	R1		; INCREMENTA O PONTEIRO DO BUFFER
	RET
FIM:	MOV	R7, #80H	; VOLTA A POSIÇÃO DE DISPLAY PARA O 
	MOV	R1, #31H	; VOLTA PONTEIRO PARA INICIO DO BUFFER
	RET
;********************************************************
DIGITO:	DB	3FH, 06, 5BH, 4FH, 66H, 6DH, 7DH, 07, 7FH, 6FH
;********************************************************
	END