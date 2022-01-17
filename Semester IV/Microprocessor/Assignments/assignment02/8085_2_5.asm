LXI H,2050H     ; load content at 2050H and map memory address
LDA 204FH       ; load content at 204FH to rA
MOV B,A         ; move content at rA to rB
MVI D,01H       ; move immediate and set content at rD to 01H
LDA 204EH       ; load content at 204EH to acc

BACK: CMP M     ; compare content at memory with rA
JZ SKIP         ; jump if zero
INR D           ; increment content at rD
INX H           ; increment memory address
DCR B           ; decrement content at rB
JNZ BACK        ; jump if not zero
MVI D,FFH       ; move immediate and set content at rD to FFH

SKIP: MOV A,D   ; jump here, move content at rD to rA
STA 204DH       ; store value at rA to 204DH
HLT             ; halt or stop programme 