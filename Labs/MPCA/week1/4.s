;Write an ALP using ARM instruction set to check if a number is even or odd.

.text
        Mov R0, #1
        And R1, R0, #1
        BEQ L1
        Mov R3, #1
        B L2
        L1: Mov R3, #0
        L2: Swi 0x011
.end

