data segment
    s dw 0
    f dw 0
    numar dw 10
    numar2 dw 3
ends

code segment
start:
    ;pentru accesarea segmentului de date
    mov ax, data
    mov ds, ax 
    mov es, ax
    
    mov cx,numar ;numarul
    xor ax,ax  
    sum:
        add ax,cx 
        dec cx
        cmp cx,0
        jg sum  
      
    mov s,ax ; in segmentul de date S(gasit in consola la vars)
    ;afiseaza rezultatul (maxim 9)      
    mov dx,ax
    add dl,'0'
    mov ah,02h
    int 21h 
        
     
    mov ah,02h 
    mov dl,' ' ; Afiseaza spatiu intre valori
    int 21h 


    int 21h  
    mov cx,numar2
    xor ax,ax
    mov ax,1
    factorial:
        mul cx
        dec cx
        cmp cx,0
        jg factorial
           
    mov f,ax           
    mov dx,ax 
    add dl,'0'
    mov ah,02h
    int 21h


; wait for any key....    
    mov ah, 1
    int 21h
    ;exit  
    mov ax,4c00h
    int 21h

ends
end start