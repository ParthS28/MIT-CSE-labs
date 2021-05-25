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
	LDR R0,=Num1
	LDR R1,[R0]
	LDR R0,=Num2
	LDR R3,[R0]
	SUBS R6,R1,R3
	LDR R2,=Result
	STR R6,[R2]
STOP
	B STOP
Num1 DCD 20
Num2 DCD 10
	AREA mydata, DATA, READWRITE
Result DCD 0
	END