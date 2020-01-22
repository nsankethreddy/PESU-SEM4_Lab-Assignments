;Copy all the values from an array a to b

.text
	mov r0, #10
	ldr r1, =a
	ldr r2, =b

L1:	ldr r3, [r1], #4
	str r3, [r2], #4
	subs r0,r0, #1
	bne L1

.data	
	a: .word 10,11,12,13,14,15,16,17,18,19
	b: .word 0,0,0,0,0,0,0,0,0,0 
.end

