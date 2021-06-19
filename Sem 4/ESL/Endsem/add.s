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
	LDR R0,=LENGTH
	LDR R2,[R0]	; storing length in R2
	MOV R3,#0	; initialise R3 to store sum
	LDR R0,=LIST
UP	LDRB R1,[R0],#1 ; list values in R1
	ADD R3,R3,R1  ; result of addition in R3
	SUB R2,R2,#1  ; counter
	CMP R2,#0 
	BNE UP		; loop if R2 != 0
	LDR R4,=CHECKSUM  ;address of result
	STRB R3,[R4]	; only storing the byte of answer hence strb
STOP
	B STOP
LIST DCB 0x28, 0x55, 0x26, 0x70, 0x45, 0x30, 0x62, 0x85
LENGTH DCD 0x7	; variable length
	AREA mydata,DATA,READWRITE
CHECKSUM DCW 0
	END