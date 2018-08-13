

data segment
   vect db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
   dim db 10  
   sum  dw 0  
   
ends


code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax
    
  
    mov bl, 0   
    mov cl,dim 
    xor ax,ax
    op_suma:
         add al,vect[bx]
         inc bl         
         loop op_suma  ;decrementeaza CL si verifica CL>0
    
    mov sum,ax  ;rezultatul se afla in sum(pe emulator se apasa vars)
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; iesire program
    int 21h  
      
ends
end start ; set entry point and stop the assembler.