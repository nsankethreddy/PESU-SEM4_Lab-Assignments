;Perform convolution using MUL and ADD instructions




.text
	MOV r0,#5
	ldr r1, =a
	ldr r2, =b
	MOV r3,#0
	loop:
		ldr r4, [r1], #4
		ldr r5, [r2], #4
		mul r6, r5,r4
		ADD r3,r3,r6
		subs r0,r0,#1
		bne loop
	swi 0x011
.data
	a: .word 1,2,3,4,5
	b: .word 1,1,2,1,2
.end
