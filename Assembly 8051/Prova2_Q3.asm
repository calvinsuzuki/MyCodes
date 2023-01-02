;******************************************************************************************
; CALVIN SUZUKI DE CAMARGO, NUSP: 11232420
;******************************************************************************************
; Um sistema de alarme baseado no 8051 possui 8 sensores magnéticos ligados no Port P0 (um
; sensor em cada bit) e uma sirene ligada no bit P1.0. Se o sistema sofrer uma invasão, os
; sensores se rompem fazendo com que o bit ligado a ele fique em nível lógico zero. Escrever um
; programa em Assembly que ao perceber um rompimento de sensor no setor 0 (qualquer dos
; quatro bits menos significativos) dispare a sirene com uma frequência de 1 KHz durante 20
; segundos, parando em seguida. Se a invasão for no setor 1 (qualquer dos quatro bits mais
; significativos) a sirene deve tocar com uma frequência de 2 KHz durante 30 segundos, parando
; em seguida. Considerar o cristal do microcontrolador de 12 MHz e que apenas um sensor se
; rompe a cada vez.
;******************************************************************************************
	ORG	0
	SJMP	PROG
;*****************************************************************************
	ORG	000BH
	SJMP	TIMER0
;*****************************************************************************
	ORG	001BH
	SJMP	TIMER1
;*****************************************************************************
PROG:   SETB	EA
        SETB	ET0		; Habilita Timer 0
        SETB	ET1		; Habilita Timer 1
	MOV	TMOD,	#11h	; Timer 0 e 1 - MODO 1
        CLR     P1.0
        CLR	20H.0		; BIT QUE INDICA SE A SIRENE ESTÁ TOCANDO
        CLR	20H.1		; BIT AUXILIAR
        MOV     P0, #0FFH
; VERIFICAÇÃO DOS SENSORES BIT A BIT
S00:	JB      P0.1, S01
        ACALL   ERRO_SETOR0
S01:    JB      P0.1, S02
        ACALL   ERRO_SETOR0
S02:    JB      P0.1, S03
        ACALL   ERRO_SETOR0
S03:    JB      P0.1, S10
        ACALL   ERRO_SETOR0
S10:	JB      P0.1, S11
        ACALL   ERRO_SETOR1
S11:    JB      P0.1, S12
        ACALL   ERRO_SETOR1
S12:    JB      P0.1, S13
        ACALL   ERRO_SETOR1
S13:    JB      P0.1, S00
        ACALL   ERRO_SETOR1
;********************************************************
;	ROTINA QUE ACIONA A SIRENE 1K	*
;********************************************************
ERRO_SETOR0:
	SETB	20H.0
        CLR	20H.1
        MOV     A, #0
	MOV	TH0,	#015h   ; Timer 60ms
	MOV	TL0,	#0A0h
	SETB	TR0		; Ativa o Timer 0
LOOP0:  CPL     P1.0
        ACALL   FREQ_1K
        JB      20H.0, LOOP0
	RET
;********************************************************
;	ROTINA QUE ACIONA A SIRENE 2K	                *
;********************************************************
ERRO_SETOR1:
	SETB	20H.0
        CLR	20H.1
        MOV     A,      #0
	MOV	TH1,	#015h   ; Timer 60ms
	MOV	TL1,	#0A0h
	SETB	TR1		; Ativa o Timer 1
LOOP0:  CPL     P1.0
        ACALL   FREQ_2K
        JB      20H.0, LOOP0
	RET
;********************************************************
TIMER0: CLR     EA
	INC     A
        CJNE	A, #166D, JUMP	; Habilita o carry quando A < 166D
JUMP:	JC	LOOP		; Se Carry = 1, reiniciar ciclo (166 vezes ou 166x60ms = 10s)
        JB      20H.1, FIM      ; Verifica a Auxiliar, se 20h.1 = 0, refaça todo o ciclo novamente (333 vezes ou 20s)
        SETB    20H.1
        MOV     A, #0
        SJMP    LOOP
FIM:    SETB    EA
        CLR    20H.0
        RETI
LOOP:	MOV	TH0,	#015h   ; Timer 60ms
	MOV	TL0,	#0A0h
	SETB	TR0		; Ativa o Timer 0
        SETB    EA
	RETI
;********************************************************
TIMER1: CLR     EA
	INC     A
        CJNE	A, #250D, JUMP	; Habilita o carry quando A < 250D
JUMP:	JC	LOOP		; Se Carry = 1, reiniciar ciclo (250 vezes ou 250x60ms = 15s)
        JB      20H.1, FIM      ; Verifica a Auxiliar, se 20h.1 = 0, refaça todo o ciclo novamente (500 vezes ou 30s)
        SETB    20H.1
        MOV     A, #0
        SJMP    LOOP
FIM:    SETB    EA
        CLR    20H.0
        RETI
LOOP:	MOV	TH1,	#015h   ; Timer 60ms
	MOV	TL1,	#0A0h
	SETB	TR1		; Ativa o Timer 0
        SETB    EA
	RETI
;********************************************************
FREQ_1K:; DELAY DE 1MS
	MOV	R1, #002h
	MOV	R0, #0F7h
	DJNZ	R0, $
	DJNZ	R1, $-5
        RETI
;********************************************************
FREQ_2K:; DELAY DE 500us
	MOV	R0, #0F9h
	DJNZ	R0, $
        RETI
;********************************************************
        END