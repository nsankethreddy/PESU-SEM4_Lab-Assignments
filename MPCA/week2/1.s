;Write an ALP using ARM instructions to find the factorial of a number

.data
        a:.WORD 4

.text
        
        LDR R0,=a
        LDR R1,[r0]
        LDR R2,[r0]
        L1:
                SUB R2,R2, #1
                CMP R2,#1
                BEQ L2
                MUL R1,R2,R1
                B L1
        L2:
                SWI 0x11
                
                
.end
        
