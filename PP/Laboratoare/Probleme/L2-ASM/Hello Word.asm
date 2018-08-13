name "Hello Word"
org 100h ; ORG is merely an indication on where to put the next piece of code/data
jmp start ; jump over data declaration
msg: db "Hello  World!", 0Dh,0Ah, 24h
start: mov dx, msg ; load offset of msg into dx.
mov ah, 09h ; print function is 9.
int 21h ; do it!
mov ah, 0
int 16h ; wait for any key....
ret ; return to operating system



; [SOURCE]: C:\emu8086\MySource\mycode.asm
