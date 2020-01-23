;Search for an element in an array if found mov its position to R7 else move -1 to r6



.text
	MOV r0,#5
	MOV r1,#0
	MOV r2,#9	;key
	ldr r3, =a
	l1:
		ldr r4, [r3]
		cmp r2,r4
		beq l2
		add r3,r3,#4
		subs r0,r0,#1
		bne l1
	mov r6,#-1
	swi 0x011
	l2:
		sub r0,r0,#1
		rsb r0,r0,#5
		mov r7, r0		;index
	swi 0x011
.data
	a: .word 5,6,7,8,9

.end
