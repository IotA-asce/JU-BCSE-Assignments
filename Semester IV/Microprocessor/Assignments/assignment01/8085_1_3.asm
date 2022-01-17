;Find the sum of the least significant 4 bits and most significant 4 bits 
;of a byte stored in memory location 2500H.Store the result in 2550H

LDA 2500H   ; load from memory location 2500H to accumulator
ANI F0H     ; and immediate with accumulator
RRC         ; rotate right accumulator, current content to the right by 1-bit position
RRC         ;
RRC         ;
RRC         ;
MOV B,A     ; move content at A to B
LDA 2500H   ; load to accumulator from 2500H
ANI 0FH     ; and immediate with accumulator
ADD B       ; A = A + B
STA 2550H   ; store value at 2550H
HLT         ; halt or stop