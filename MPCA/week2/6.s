.text
	mov r0,#10
	mov r2, #0
	ldr r1,=a
L1:
	ldr r3,[r1],#4
	sub r0,r0,#1
	add r2,r2,r3
	cmp r0, #0
	bne L1
.data	
	a: .word 10,11,12,13,14,15,16,17,18,19
.end
