.data
        A: .byte 1,2,3,4,5,6,7,8,9,10
.text
        MOV R2,#7
        LDR R3,=A
        MOV R5, #0 
        MOV R7, #0
        MOV R8, #9
        loop:  
                LDR R3,=A
                CMP R8,R7
                BMI notfound
                ADD R9, R7, R8
                MOV R6,R9,LSR #1
                ADD R3,R3,R6
                LDRB R4,[R3] 
                MOV R5, R6
                CMP R4,R2
                BEQ found
                BPL subb
                BMI add
                add:
                ADD R7,R6,#1 
                b loop
                subb:
                SUB R8,R6,#1 
                b loop
       
        notfound: MOV R9,#1    
        SWI 0x011
        found: MOV R10,R5 
        SWI 0x011
.end
	

