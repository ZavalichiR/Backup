                                                                            


name "sortare_metoda_bulelor"


.MODEL SMALL
.STACK 100H

.DATA
v db 5, 2, 8, 9, 1, 7, 3, 0, 4, 6
.CODE
mov ax, @DATA
mov ds, ax     ;initialize data segment

mov cx, 10  ;length
mov dh, 0
mov dl, 0
mov si, 0  ;i
mov di, 0  ;j
push cx
FOR1:

mov di, si
cmp di, 0
jle WHILEEND
WHILE1:

mov ah, [bx+di]
mov al, [bx+di-1]
cmp ah, al
jge WHILEEND
mov [bx+di], al
mov [bx+di-1], ah
; else swap
dec di
cmp di, 0
jge WHILE1

WHILEEND:
inc si
dec cx
cmp cx, 0
jge FOR1


pop cx
mov si, 1
bucla:



mov ah, 2h
mov dl, [bx+si]
add dl, '0'
int 21h
inc si
dec cx
cmp cx, 0
jg bucla


mov ax, 4C00h
int 21h



