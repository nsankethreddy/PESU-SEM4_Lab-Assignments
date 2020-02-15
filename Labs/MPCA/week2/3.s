;ADD 2 numbers loaded from memory

.text

LDR r0,=a
LDR r0,[r0]
LDR r1, =b
LDR r1,[r1]

ADD r2, r1,r0
LDR r3, =c
STR r2, [r3]

.data
a: .word 10
b: .word 20
c: .word 0
.end
