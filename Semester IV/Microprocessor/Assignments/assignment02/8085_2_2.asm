LXI H,0000H     ; load rp H-L with value 0000H
LXI D,0000H     ; load rp D-E with value 0000H

LDA 2050H       ; load content at 2050H to acc
ADI 00H         ; add immediate with content at rA
JZ EXIT         ; jump if zero at acc
MOV E,A         ; move content at acc to rE

LDA 2051H       ; load content at 2051H to acc
ADI 00H         ; add immediate with content at rA
JZ EXIT         ; jump if zero at rA
MOV C,A         ; move content at rA to rC

BACK: DAD D     ; jump here, double add rp D-E
DCR C           ; decrement content at C
JNZ BACK        ; jump if not zero

EXIT: SHLD 2052H; jump here, store H-L rp using direct addressing at 2052H
HLT             ; halt or stop programme