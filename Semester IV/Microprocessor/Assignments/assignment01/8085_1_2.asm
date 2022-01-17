; Find  the  sum  of  N  numbers  stored  in  consecutive  locations  starting  from  2500H.  
; The value of N is stored in 2200H. Store the result in locations 2300Hand 2301H.

; we decrement the value of N on every iteration untill it reached 0 and 
; add up the values by incrementing the addresses

LXI H,2500H     ; Load from memory address 2500H to memory
LDA 2200H       ; load to accumulator from address 2200H
MOV C,A         ; move value from accumulator to register C
MVI A,00H       ; set value of accumulator A to 00H
MVI B,00H       ; set value of register B for carry to 00H
LOOP:ADD M      ; jump here from condition JNZ
JNC SKIP        ; jump if no carry
INR B           ; increment value at register B for carry
SKIP:INX H      ; increment address for next value
DCR C           ; decrement value at C
JNZ LOOP        ; jump if not 0
STA 2300H       ; store value at accumulator to address 2300H
MOV A,B         ; move value of carry from address B to accumulator
STA 2301H       ; store value of carry from accumulator to address 2301H
HLT             ; halt or stop program