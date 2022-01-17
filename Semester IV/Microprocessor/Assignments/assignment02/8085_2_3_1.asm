LXI H,2050H     ; load content at 2050H to rH and map address to rH
LDA 204FH       ; load content at 204FH to rA
MOV C,A         ; move content at rA ro rC
SUB A           ; set zero flag, content at rA to 00H

BACK:CMP M      ; jump here, compare value at A with mapped memory address
JNC SKIP        ; jump if no carry 
MOV A,M         ; move content at memory to rA

SKIP: INX H     ; increment mapped memory address
DCR C           ; decrement content at rC
JNZ BACK        ; jump if not zero
MOV M,A         ; move content at rA to memory
HLT             ; halt or stop programme
 