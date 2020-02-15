.text
        MOV R3, #24 
        MOV R4, #0
        MOV r8, #2
        loop:
        CMP R3, #1
        BEQ end
        MOV R5,R3,LSR #1
        MUL R6, R5, R8 
        SUB R7, R3, R6
        MOV R3,R5 
        CMP R7, #1
        BEQ add
        b loop
        add: ADD R4, R4, #1
        b loop
        end: ADD R4, R4, #1
        SWI 0x011
.end
