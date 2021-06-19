	AREA RESET, DATA, READONLY
	EXPORT __Vectors
		
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	LDR R0,=input
	LDR R1,=result
	LDR R2,[R0]
	BL FCT
	STR R2,[R1]
HERE B HERE
FCT PUSH{R3,LR}
	MOV R3,R2
	CMP R2,#0
	BNE DWN
	MOV R2,#1
	B DWN1
DWN SUB R2,#1
	BL FCT
	MOV R4,R3
	MUL R2,R4
DWN1 POP{R3,LR}
	BX LR
	
input DCD 0x4
	AREA mydata, DATA, READWRITE
result DCD 0
	END