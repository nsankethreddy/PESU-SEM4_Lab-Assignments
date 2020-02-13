.data
        A: .asciz "aabaa"
        B: .asciz "Found"
        C: .asciz "Not found"
.text
        LDR r1,=A
        LOOP:
        LDRB r2,[r1],#1
        CMP r2,#'\0'
        BEQ NF
        CMP r2,#'c'
        BNE LOOP
        LDR r0,=B
        SWI 0x02
        SWI 0x011
        NF:
        LDR r0,=C
        SWI 0x02
        SWI 0x011
.end
