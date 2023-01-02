;*********************************************************************************************
; ALUNO: CALVIN SUZUKI DE CAMARGO NUSP: 11232420
; OBJETIVO:
; Faça um programa que transfira um dado armazenado na memória RAM externa do 8051 da
; posição 1200H para a posição 30h da RAM Interna.
;*********************************************************************************************

	ORG	0
	MOV	DPTR, #1200H
	MOVX	A, @DPTR
	MOV	30H, A
	SJMP $
	END
