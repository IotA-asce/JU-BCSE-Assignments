;Write a program to count the ‘1’s and ‘0’s of a byte stored in 2500H. 
;Store the  result in 2610Hand 2511H, respectively

LDA 2500H3      ; load to accumulator from 2500H
MOV E,A         ; move content from register E to A
MVI B,00H       ; move immediate initialize C to 00H
MVI C,00H       ; initialize C to 00H
MVI D,08H       ; initialize D to 00H
LOOP:MOV A,E    ; jump here and move content ar E to A
RRC             ; rotate right accumulator content
MOV E,A         ; move from accumulator to E
RLC             ; rotate left accumulator content
ANI 01H         ; and immediately with accumulator
JZ SKIP         ; jump if equal to zero
INR B           ; increment content at B
SKIP:DCR D      ; skip jump here, decrement content at D
JNZ LOOP        ; jump if not zero
MOV A,B         ; move content at B to A
STA 2610H       ; store content at A to 2610H
MVI A,08H       ; set content at A to 00H
SUB B           ; A = A - B
STA 2511H       ; store content atc accumulator
HLT             ; halt or stop program