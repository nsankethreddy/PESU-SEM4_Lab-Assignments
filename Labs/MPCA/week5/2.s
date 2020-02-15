.data
        A: .asciz "aabaa"
        B: .asciz  ""  
.text
        LDR r1,=A
        LDR r0,=B
        LOOP:
        LDRB r2,[r1],#1
        STRB r2,[r0],#1
        CMP r2,#'\0'
        BNE LOOP
        LDR r0,=B
        SWI 0x02
        SWI 0x11
.end
