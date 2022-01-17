LDA 201EH       ; load from memory address 201EH to acc
MOV L,A         ; move from A to rL

LXI B,2000H     ; load content at 2000H to B
LXI D,3000H     ; load content at 3000H to D

BACK: LDAX B    ; loop jump here, Load acc from memory pointed by extended register pair denoted as BC
STAX D          ; store accumulator contents in memory pointed by extended register denoted as DE
INX B           ; increment memory address currently for B
INX D           ; increment memory address currently for B
DCR L           ; decrement value at L
JNZ BACK        ; jump if not zero

LDA 201FH       ; load to acc from 201FH
CPI 00H         ; compare immediate with acc and check zero flag
JZ END          ; jump if zero
MOV H,A         ; move from acc to rH
LDA 201EH       ; load from 201EH to acc
MOV L,A         ; move from acc to rL
INX B           ; increment address to B

LOOP: DCX B     ; loop jump here, decrement extended register, address to B
DCR H           ; decrement content at H
JNZ LOOP        ; jump if not zero

LXI D,3000H     ; load content at 3000H to D and set memory address
SKIP: LDAX D    ; skip jump here, 
STAX B          ; store accumulator contents in memory pointed by extended register denoted as BC
SUB A           ; set zero flag
STAX D          ; store accumulator contents in memory pointed by extended register denoted as DE
INX D           ; increment address to rD
INX B           ; increment address to rB
DCR L           ; decrement content at L 
JNZ SKIP        ; jump if not zero

END: HLT        ; end jump here, halt or stop