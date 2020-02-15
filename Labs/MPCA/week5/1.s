.data
       A: .ASCIZ "mpcalab"
 
 
.text
        LDR R0,=A
        MOV R1,#0
        LOOP:LDRB R3,[R0],#1
             ADD R4,R4,#1
             CMP R3,#0
             BNE LOOP
             SUB R4,R4,#1
        SWI 0X11 
