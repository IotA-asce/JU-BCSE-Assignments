LDA 204FH           ; load content at 204FH
DCR A               ; decement content at rA
MOV B,A             ; move content at rA to rB
BACK2:LXI H,2050H   ; load content at 2050H to rH, map memory address
MOV C,A             ; move content at rA to rC

BACK1:MOV E,M       ; jump here, move content at memory to rE
INX H               ; increment memory address
MOV A,M             ; move content at memory to rA
CMP E               ; compare content at rE with content at rA
JC SKIP             ; jump if carry
MOV M,E             ; move content at rE to memory
DCX H               ; decrement memory address
MOV M,A             ; move content at rA to memory
INX H               ; increment memory address

SKIP:DCR C          ; jump here, decrement content at rC
JNZ BACK1           ; jump if not zero
DCR B               ; decrement content at rB
JNZ BACK2           ; jump if not zero
HLT                 ; halt or stop
