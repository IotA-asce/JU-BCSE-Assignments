; Load  the  contents  of  the  memory  locations  2200Hand  2201H into  registers.  
; Add  these registers and store the result in memory locations 2202H and 2203H
;TO ADD FOR CARRY
; INPUT NO 1->INPUT NO 2->ADD->STORE
;                          |->CARRY -> STORE
LXI H,2200H     ; (2200H<-AA)
MOV A,M         ; (A<-AA)
INX H           ; (2201H<-AB)
MVI B,00H       ; INITIALIZE TO 00H FOR CARRY
ADD M           ; 8-BIT ONLY 
JNC SKIP        ; CONDITIONED JUMP IF NO CARRY
INR B           ; INCREMENT THE VALUE AT REGISTER B BY 1
SKIP:STA 2202H  ; JUMP HERE
MOV A,B         ; MOVE FROM REGISTER B TO ACCUMULATOR
STA 2203H       ; STORE AT 2203H
HLT             ; HALT OR STOP PROGRAM