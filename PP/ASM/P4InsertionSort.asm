

        ;insertion sort
        
;   for (i= 1 i< N-1;++i)
;    {
;         aux = a[i];
;         j = i-1;
;         while( (j>=0) && (a[j]>aux) )
;          {    
;               a[j+1] = a[j];
;               j = j-1;
;          }
;       a[j+1] = aux;
;    }


data segment
    vector db 10,8,9,7,5,6,4,3,2,1
    dim db 10
ends

code segment
start:

	mov ax,data
    mov ds,ax
    mov es,ax
    
    xor cx,cx 
    mov cl,1
    
    for:
    mov bx,cx
    mov al,vector[bx]
    dec bx
    while:
		cmp bx,0
		jl end_while
		mov ah,vector[bx]
		cmp ah,al
		jl end_while
		mov vector[bx+1],ah
		dec bx
		jmp while
    end_while:
    mov vector[bx+1],al 
    inc cl
    cmp cl,dim
    jne for
    
    
    xor si,si
    mov cl,dim
    mov ah,02h 
    
    afisare:
        mov dl,vector[si]    
        add dl,'0'
        int 21h
        
        mov dl,' '
        int 21h
        
        inc si
        loop afisare
                    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
