;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Faça um programa que some dois números de 8 bits, armazenados em posições subsequentes
; na área de RAM interna (endereços 30h e 31h). O resultado deve ser armazenado na posição
; seguinte aos dados.
;*********************************************************************************************

	ORG	0
	CLR	A
	ADD	A, 30H
	ADD	A, 31H
	MOV	32H, A
	SJMP	$
	END