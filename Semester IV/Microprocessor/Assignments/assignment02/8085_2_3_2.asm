LXI H,2050H     ; load content at 2050H to rH and map the memory address
LDA 204FH       ; load content at 204FH to rA
MOV C,A         ; move content at rA to rC
MVI A,FFH       ; move immediate, set rA content to FFH

BACK:CMP M      ; compate memory content with rA
JC SKIP         ; jump if carry
MOV A,M         ; move content at memory to rA

SKIP: INX H     ; jump here, increment memory address
DCR C           ; decrement content at rC
JNZ BACK        ; jump if not zero
MOV M,A         ; move content at rA to memory
HLT             ; halt or stop programme
 
