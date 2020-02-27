.text 
    mov r0,#0
    loop:
        swi 0x201
        add r0,r0,#1
        mov r4,#64000
    delay:
        sub r4,r4,#1
        cmp r4,#0
        bne delay
    cmp r0,#3
    ble loop
    .end
