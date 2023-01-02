;******************************************************************************************
; CALVIN SUZUKI DE CAMARGO, NUSP: 11232420
;******************************************************************************************
;Usando instruções que endereçam bits no 8051, escrever um programa em Assembly que
;mova os bits do endereço de byte 20h para o endereço de byte 2Fh na ordem inversa, ou seja,
;o Bit Menos Significativo do endereço 20h vai para o Bit Mais Significativo do endereço 2Fh e
;assim sucessivamente até o Bit Mais Significativo do endereço 20h seja movido para a posição
;menos significativa do endereço 2Fh
;******************************************************************************************
        ORG     0
        JNB     20H.0, B00
        SETB    2FH.7
        SJMP    B1
B00:    CLR     2FH.7
B1:     JNB     20H.1, B01
        SETB    2FH.6
        SJMP    B2
B01:    CLR     2FH.6
B2:     JNB     20H.2, B02
        SETB    2FH.5
        SJMP    B3
B02:    CLR     2FH.5
B3:     JNB     20H.3, B03
        SETB    2FH.4
        SJMP    B4
B03:    CLR     2FH.4
B4:     JNB     20H.4, B04
        SETB    2FH.3
        SJMP    B5
B04:    CLR     2FH.3
B5:     JNB     20H.5, B05
        SETB    2FH.2
        SJMP    B6
B05:    CLR     2FH.2
B6:     JNB     20H.6, B06
        SETB    2FH.1
        SJMP    B7
B06:    CLR     2FH.1
B7:     JNB     20H.7, B07
        SETB    2FH.0
        SJMP    FIM
B07:    CLR     2FH.0
FIM:    SJMP $
        END
