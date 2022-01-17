LDA 21FFH       ; load to A from 21FFH
MOV D,A         ; move from acc to D
LXI H,2200H     ; loax to rp HL from 2200H
MVI B,00H       ; initialize B to 00H
MVI C,00H       ; initialize C to 00H
SUB A           ; substracts contents from acc and sets zero flag

BACK: MOV A,M   ; jump here, move from memory to A
ANI 80H         ; and immediate with A
JZ EXIT         ; jump if zero
MOV A,M         ; move from memory to A
ANI 01H         ; and immediate with A
JZ EXIT         ; jump if zero 
SUB A           ; substracts contents from acc and sets zero flag
MOV A,C         ; move from C to A
ADD M           ; A = A + M
MOV C,A         ; move from A to r C
JNC EXIT        ; jump if no carry
INR B           ; invrement content of B

EXIT:INX H      ; jump here, increment address
DCR D           ; decrement content at D
JNZ BACK        ; jump if not zero

LXI H,2500H     ; load to rp HL from 2500H
MOV M,C         ; move from C to memory location set most recently
INX H           ; increment memory address
MOV M,B         ; move from B to memory address
HLT             ; halt or stop programme