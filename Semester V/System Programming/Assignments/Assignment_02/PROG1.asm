; write and test a MASM program to add and substract two 16 bit numbers

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;												;;
;;                    addition                  ;;
;;												;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

dosseg
.model small
.stack 100h
.data
msg1 db 10,13,'Enter 1st number:$'
msg2 db 10,13,'Enter 2nd number:$'
msg3 db 10,13,'Sum is $'

.code
main proc

mov ax,@data
mov ds,ax

lea dx,msg1
mov ah,09h
int 21h

mov ah,01h
int 21h

mov bl,al
lea dx,msg2
mov ah,09h
int 21h

mov ah,01h
int 21h
mov ch,al 			;second number first digit

mov ah,01h
int 21h
mov cl,al			;second number second digit
				;both number input taking is done.
				;now we start computing lower digit addition first

mov al,bl
mov ah,00h			;clear ah first
add al,cl			;al=al+cl, if carry generated then it is stored in ah
aaa

add ax,3030h			;convert to ascii code
mov bl,al			;store lower digit sum of the result

				;now we start computing higher digit addition alongwith carry 'ah'

mov al,ah			;store carry
mov ah,00h
add al,bh			;al+=bl
add al,ch			;al+=cl
aaa

add ax,3030h			;convert to ascii code
mov bh,al			;store al in bh;store higher digit sum of the result

mov cl,ah			;store final carry in cl

lea dx, msg3
mov ah,09h
int 21h

mov dl,cl
				;print carry
mov ah,02h
int 21h
				;print higher digit
mov dl,bh
mov ah,02h
int 21h
				;print lower digit
mov dl,bl
mov ah,02h
int 21h

mov ah,4ch
int 21h
				
main endp
end main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                      ;;
;; substraction                         ;;
;;                                      ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

dosseg
.model small
.stack 100h
.data
msg1 db 10,13,'Enter 1st number: $'
msg2 db 10,13,'Enter 2nd number :$'
msg3 db 10,13,'Difference is $'
msg4 db 10,13,'Difference is negative$'
.code
main proc

				;initialize the data
mov ax,@data
mov ds,ax

lea dx,msg1
mov ah,09h
int 21h
				;input first number 
mov ah,01h
int 21h
mov bh,al 			;first number first digit

mov ah,01h
int 21h
mov bl,al			;first number second digit

lea dx,msg2
mov ah,09h
int 21h
				;second first number 
mov ah,01h
int 21h
mov ch,al 			;second number first digit

mov ah,01h
int 21h
mov cl,al			;second number second digit
				;both number input taking is done.
				
cmp cx,bx			;compare the diffrence
jz ZERO				;if both are same then zero flag=1 detected then jump to ZERO label
jnc NEGATIVE			;if source is greater than destiantion jump to NEGATIVE label
clc				;clear carry flag i.e. difference is positive hence carry reset to be done
				;for later calculation
mov al,bl
mov ah,00
sub al,cl			;al=al-cl
aas
mov cl,ah			;store carry
add al,30h			;convert to ascii code
mov bl,al			;bl=al ;store lower digit of the result

mov ah,00
sub bh,ch			;bh=bh-ch
mov al,bh			;al=bh
aas
add al,cl			;al=al+cl
add al,30h			;convert ascii code	
mov bh,al			;store higher digit of the result
jmp DISP

ZERO:
lea dx,msg3
mov ah,9
int 21h
mov ax,bx			;move bx into ax
sub ax,cx			;ax=ax-cx
mov bh,ah			;bh=ah
add al,30			;convert to ascii
mov dl,al
mov ah,2
int 21h
add bh,30			;convert to ascii
mov dl,bh
mov ah,2
int 21h
jmp FULL

NEGATIVE:
mov al,cl
mov ah,00
sub al,bl
aas
mov bl,ah
add al,30
mov cl,al
mov ah,00
sub ch,bh
mov al,ch
aas
add al,bl
add al,30
mov ch,al
lea dx, msg4
mov ah,9
int 21h
mov dl,ch
mov ah,02h
int 21h				;print higher digit
mov dl,cl
mov ah,2
int 21h
jmp FULL

DISP:
lea dx,msg3
mov ah,9
int 21h
mov dl,bh
mov ah,2
int 21h				;print higher digit 
mov dl,bl
mov ah,2
int 21h				;print lower digit




FULL:
mov ah,4ch
int 21h
				


main endp
end main
