
data segment

vector db 4,8,5,9,1,2,3,6,7,0
ok db 1                              ;ok=1
dim db 10

ends

code segment
start:
    

mov ax,data
mov ds,ax
mov es,ax


while:
  xor dl, dl ; DL - ok = 0            ; ok=0
  
                                      
  xor si,si                           ; si = 0 (i=0)
  mov cl, dim                         ; CX = dim (nr de elemente)
  dec cl                              ; for si=0 to dim-1
  for:
    mov ah, vector[si]                ; AH = v[i]
    ;inc si
    mov al, vector[si+1]              ; AL = v[i+1]
    
    cmp ah, al                        ; if (v[i] < v[i+1])
    jge if
      mov vector[si+1], ah            ; v[i+1] <- AH(v[i]) (si este deja incrementat)
      ;dec si          ; i--
      mov vector[si], al              ; v[i]   <- AL(v[i+1])
      
      
      
      mov dl,ok                       ; ok=1
    if: 
    inc si                            ; i++
  loop for                            ; cl-- apoi sare la for
                               
  cmp dl, 1                           ; if dl=1
je while                              ; je- jump daca dl=1

mov ah, 02h
xor si, si
mov cl, dim
afisare:
  mov dl, vector[si]
  add dl, '0'                         ; Pentru valori numerice (0-9)
  int 21h

  mov dl, ' '                         ; Afiseaza un spatiu intre valori
  int 21h
  inc si
loop afisare       
   
mov ah,1
int 21h                               ; Press any key
mov ax, 4c00h                         ; Return 0
int 21h
ret
ends
end start






