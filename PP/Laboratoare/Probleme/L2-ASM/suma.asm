mov cx,10
mov ax,0
bucla:
    add ax,cx 
    dec cx
    cmp cx,0
    jg bucla
    ;sau loop bucla
mov dx,ax
mov ah,02h
int 21h
mov ax,4c00h
int 21h