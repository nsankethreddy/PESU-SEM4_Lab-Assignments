;Generate Fibonacci series




.text
	MOV r0,#10
	MOV r1,#0
	MOV r2, #1
	ldr r3, =a
	loop:
		str r1, [r3]
		add r3,r3,#4
		add r4,r1, r2
		MOV r1,r2
		MOV r2,r4
		subs r0,r0,#1
		bne loop
	swi 0x011
.data
	a: .word
.end
