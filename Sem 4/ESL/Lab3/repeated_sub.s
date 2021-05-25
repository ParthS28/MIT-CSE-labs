	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY 
	EXPORT Reset_Handler
		
Reset_Handler
	LDR R0,=N1
	LDR R1,=N2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R7,=Result
	MOV R4,#0
	MOV R5,#0
UP  CMP R2,R3
	BCC Store
	SUB R2,R3
	ADD R4,#1
	B UP
Store STR R4,[R6],#4
	STR R2,[R6]
	STR R4,[R7]
STOP
	B STOP
N1 DCD 10
N2 DCD 5

	AREA mydata, DATA, READWRITE
Result DCD 0
		
	END
	