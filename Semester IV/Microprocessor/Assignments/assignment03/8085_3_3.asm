LDA 2060H       ; load to accumulator from 2060H
MOV D,A         ; move form A to rD
XRA A           ; exclusive or with acc, sets zero flag, content at acc = 00H
MOV B,A         ; move from acc to B
LXI H,2050H     ; load from 2050H to HL rp
MOV M,A         ; move from memory to Acc
INR A           ; increment content at A
INX H           ; increment memory address to read from
MOV M,A         ; move from acc to memory address
DCR D           ; decrement content at D
DCR D           ; decrement content at D

LOOP: ADD B     ; loop jump here, A = A + B
MOV B,M         ; move from memory address to B
INX H           ; increment memory address
MOV M,A         ; move content at acc to memory address
DCR D           ; decrement content at D
JNZ LOOP        ; jump if not zero
HLT             ; halt or stop programme