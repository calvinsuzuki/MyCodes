;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; - EXT0, atendida prioritariamente, P1->5000h(xdata)
; - EXT1, com baixa prioridade, 5000h(xdata)->7Fh
; - TIMER0, (a cada 10 ms), alta prioridade, 7Fh->5200h(xdata)
; - TIMER1, (a cada 60 ms), baixa prioridade, 5200h(xdata)->5000h(xdata)
; - O programa deve ficar em Loop infinito
;*********************************************************************************************
	ORG	0
	SJMP	PROG
;*****************************************************************************
	ORG	3
	SJMP	EXT_0 ; INT0 (P3.2)
;*****************************************************************************
	ORG	000BH
	SJMP	TIMER0 ;
;*****************************************************************************
	ORG	0013H
	SJMP	EXT_1 ; INT1 (P3.3)
;*****************************************************************************
	ORG	001BH
	SJMP	TIMER1
;*****************************************************************************
PROG:	SETB	EA
	; EXTERNAS
	SETB	EX0		; Habilita EXT_0
	SETB	EX1		; Habilita EXT_1
	; TIMERS
	SETB	ET0		; Habilita Timer 0
	SETB	ET1		; Habilita Timer 1
	MOV	TMOD,	#11h	; Timer 0 e 1 - MODO 1
	; PRIORIDADE
	SETB	IP.0		; Priodidade alta EX_0
	SETB	IP.1		; Priodidade alta TIMER_0
	; Timer 0 10ms
	MOV	TH0,	#0D8H
	MOV	TL0,	#0F0H
	SETB	TR0		; Ativa o Timer 0
	; Timer 1 50ms
	MOV	TH1,	#015H
	MOV	TL1,	#0A0H
	SETB	TR1		; Ativa o Timer 1
	SJMP	$
;*****************************************************************************
EXT_0:	MOV	A, P1
	MOV	DPTR, #5000H
	MOVX	@DPTR, A
	RETI
;*****************************************************************************
EXT_1:	MOV	DPTR, #5200H
	MOVX	A, @DPTR
	MOV	7FH, A
	RETI
;*****************************************************************************
TIMER0:	MOV	DPTR, #5200H
	MOVX	A, @DPTR
	MOV	7FH, A
	;	Timer 0 10ms
	MOV	TH0,	#0D8H
	MOV	TL0,	#0F0H
	RETI
;*****************************************************************************
TIMER1:	MOV	DPTR, #5200H
	MOVX	A, @DPTR
	MOV	DPTR, #5000H
	MOVX	@DPTR, A
	;	Timer 1 50ms
	MOV	TH1,	#015H
	MOV	TL1,	#0A0H
	RETI
;*****************************************************************************
	END