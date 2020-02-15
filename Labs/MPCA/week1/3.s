;Write an ALP to add 5 numbers where values are present in registers.

.text
        Mov R0, #1
        Mov R1, #2
        Mov R2, #3
        Mov R3, #4
        Mov R4, #5
        Add R5, R1, R2
        Add R6, R3, R4
        Add R7, R0, R5
        Add R8, R7, R6

.end
