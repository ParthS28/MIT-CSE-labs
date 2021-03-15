	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		MOV R1, #10
		MOV R2, #20
		ADD R0, R1, R2
STOP 	B STOP	
		END