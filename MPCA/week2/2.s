;Write an ARM instruction in which 1 is stored in R1 if R0 is 0,2 is stored if R0 is positive or store 3 if R0 is negative

.text
	MOV r0, #-1
	CMP r0, #0
	BNE L1
	MOV r1, #1
	B EXIT
L1:
	MOVMI r1, #3
	MOVPL r1, #2
EXIT:	

.end
