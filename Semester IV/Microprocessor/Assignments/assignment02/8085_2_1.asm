LDA 2050H   ; load from 2050H to acc
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
MOV B,A     ; move content at rA to rB 
LDA 2051H   ; load content at 2051H to rA
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
RLC         ; rotate left content of acc
MOV C,A     ; move content at rA to rC
ANI 0FH     ; and immediate with content of rA
MOV D,A     ; move content at rA to rD
MOV A,B     ; move content at rB to rA
ANI F0H     ; and immediate with content at rA
ORA D       ; or accumulator content with rD
STA 2052H   ; store content at acc to 2052H
MOV A,C     ; move content at rC to rA
ANI F0H     ; and immediate with acc
MOV D,A     ; move content at acc to rD
MOV A,B     ; move content at rB to rA
ANI 0FH     ; and immediate with acc
ORA D       ; or content at acc with content at rD
STA 2053H   ; store content at acc to 2053H
HLT         ; halt or stop programme