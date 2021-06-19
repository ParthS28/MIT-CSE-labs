	AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler	

Reset_Handler
		
	MOV R1, #5
	MOV R2, #2
	MOV R3, #8
	MOV R4, #1
	MOV R5, #0
	MOV R6, #4
	MOV R7, #6
	MOV R8, #9
	MOV R9, #3
	MOV R10, #7
	STMIA R13!, {R1-R10}
	MOV R0, R13 ;r0 stores the stack top
	MOV R2, #10 ;r2 stores number of elements in stack
	MOV R8,#0	;r8 is counter for outer loop
ol	CMP R8,R2
	BEQ exit
		
	MOV R1, R0	
	MOV R3, R0
	SUB R3, #4
	ADD R9,R8,#1
il	CMP R9,R2
	BEQ exin
	ADD R9,#1
	LDMDB R1,{R4}
	LDMDB R3!,{R5}
	CMP R5,R4
	BLT il
	STMDB R1,{R5}
	STM R3,{R4}
	B il
exin SUB R0,#4
	ADD R8,#1
	B ol
		
exit	
	LDMDB R13!,{R1-R10}
stop 	B stop

	AREA mydata,DATA,READWRITE
END 
