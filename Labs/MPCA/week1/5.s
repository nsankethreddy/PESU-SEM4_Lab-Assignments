;Compare the value of R0 and R1, add if R0 = R1, else subtract

.text
        Mov R0, #1
        Mov R1, #2
        Subs R2, R0, R1
        BEQ L1
        Subs R3, R0, R1
        B L2
        L1: Add R3, R1, R2
        L2: Swi 0x011
        
.end
