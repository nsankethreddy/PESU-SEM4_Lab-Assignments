;Add all the elements in a array/Byte instructions



.text
	MOV r0,#10
	MOV r1,#0
	ldr r3, =a
	loop:
		ldrb r4, [r3]
		add r1,r1, r4
		add r3,r3,#1
		subs r0,r0,#1
		bne loop
	swi 0x011
.data
	a: .byte 5,6,7,8,9,11,12,13,14,1

.end
