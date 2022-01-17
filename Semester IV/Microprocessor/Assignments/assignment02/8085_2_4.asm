LXI B,2100H     ; load content at 2100H to rB and map memory address
LXI D,2200H     ; load content at 2200H to rD and map memory address
LDA 204FH       ; load content at 204FH to rA
CPI 00H         ; compare immediate with accumulator
JZ END          ; jump if zero
LXI H,2050H     ; load content at 2050H and map memory address

LOOP: MOV A,M   ; move content at memory to rA
ANI 01H         ; and immediate with rA
MOV A,M         ; move content at memory to rA
JZ EVEN         ; jump if zero
STAX D          ; store accumulator contents at memory pointed by extended D-E
INX D           ; increment memory address mapped to rD
JMP LEND        ; unconditioned jump

EVEN: STAX B    ; jump here, store accumulator contents at memory pointed by extended B-C
INX B           ; increment memory address mapped to rB

LEND: INX H     ; jump here, increment memory address mapped to rH
LDA 204FH       ; load content at 204FH to rA
DCR A           ; decrement content at rA
STA 204FH       ; store content at accumulator/rA to 204FH
JNZ LOOP        ; jump if not zero

END: MOV A,C    ; jump here, move content at rC to rA
STA 2300H       ; store content at 2300H to rA
MOV A,E         ; move content at rE to rA
STA 2301H       ; store content at rA to 2301H

HLT             ; halt or stop programme