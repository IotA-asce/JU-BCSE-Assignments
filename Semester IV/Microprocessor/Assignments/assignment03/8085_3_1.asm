; A  set  of Ndata  bytes  is  stored  in  m/m  locations  starting  from  2501H.  The  value  of Nis stored in 2500H. Write a program to store these data bytes from m/m location 2600Hif D0or D7is 1; otherwise reject the data byte
LDA 2500H       ; load from 2500H to accumulator
MOV B,A         ; move from accumulator to B
LXI H,2501H     ; load to Register H from 2501H
LXI D,2600H     ; load to register D from 2600H

LOOP: MOV A,M   ; Loop jump here, move from memory to accumulator
ANI 81H         ; and immediate with accumulator
JZ EXIT         ; jump if zero
MOV A,M         ; move from memory to accumulator
STAX D          ; store accumulator contents in register pair DE
INX D           ; increment contents of register pair by 1

EXIT: INX H     ; jump here if zero and increment HL register pair
DCR B           ; decrement contents at register B
JNZ LOOP        ; jump if not zero
HLT             ; halt or stop programme