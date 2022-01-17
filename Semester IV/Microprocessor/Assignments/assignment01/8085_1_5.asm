; Write a program to sum two 16-bits binary numbers.

MVI H,00H       ; MOVE immediate 00H to memory
LXI B,ABCDH     ; Store ABCDH into the BC Register Pair.
LXI D,5141H     ; store 5141H to DE register pair
MOV A,C         ; move from C to A
ADD E           ; add value of E to A, A = A + E
STA 2500H       ; store value at A to address 2500H
MOV A,B         ; move value at B to A
ADC D           ; add value at D to A, A = A + D
JNC SKIP        ; jump if no carry
INR H           ; increment address to read to memory from
SKIP:STA 2501H  ; skip jump here and store value at accumulator to 2501H
MOV A,H         ; move from memory to accumulator
STA 2502H       ; store value at accumulator to 2502H
HLT             ; halt or stop program