;Perform convolution using MLA instruction



.text
	MOV r0,#5
	ldr r1, =a
	ldr r2, =b
	MOV r3,#0
	loop:
		ldr r4, [r1], #4
		ldr r5, [r2], #4
		mla r3, r4, r5,r3
		subs r0,r0,#1
		bne loop
	swi 0x011
.data
	a: .word 1,2,3,4,5
	b: .word 1,1,2,1,2
.end
