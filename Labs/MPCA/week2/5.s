;GCD of two numbers 
.text
	MOV R1,#60
	MOV R2,#24
	L1:
		CMP R0,R1
		SUBGT R0,R0,R1
		SUBLT R1,R1,R0
	BNE L1
.end
		
