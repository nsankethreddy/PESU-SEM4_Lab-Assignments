.text
    mov r0,#30
    mov r1,#7
    mov r7,#0
    ldr r8,=num
    ldr r8,[r8]
    ldr r2,=str
    
loop:
    swi 0x204
    bl sum
    cmp r0,#0
    subne r0,r0,#1
    swieq 0x011
    b loop
    
sum:
    cmp r7,r8
    addne r7,r7,#1
    bne sum
    swi 0x206
    mov r7,#0
    mov pc,lr
    
.data
    str: .asciz "PESU"
    num: .word 15000
