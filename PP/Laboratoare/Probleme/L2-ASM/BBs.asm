
.data

v db 4,5,8,9,1,2,3,6,7,0
n db 10

.code

mov bx, offset v ; BX = V
bs_start:
  xor dl, dl ; DL - permutari = 0
  xor si,si ; Si = 0
  mov cl, [n]; CX = nr elemente
  dec cl      ; for si=0 to n-1
  for_loop:
    mov ah, [bx+si] ; AH = v[i]
    inc si
    mov al, [bx+si] ; AL = v[i+1]
    cmp ah, al ; if (v[i] < v[i+1])
    jge no_swap
      mov [bx+si], ah ; v[i+1] <- AH(v[i]) (si este deja incrementat)
      dec si          ; i--
      mov [bx+si], al ; v[i]   <- AL(v[i+1])
      inc si          ; incrementam din nou i
      inc dl; permutari++
    no_swap:
  loop for_loop
                               
  cmp dl, 0; if permutari == 0
jne bs_start

mov ah, 02h
xor si, si
mov cl, [n]
print_for:
  mov dl, [bx + si]
  add dl, '0' ; Pentru valori numerice (0-9)
  int 21h

  mov dl, ' ' ; Afiseaza un spatiu intre valori
  int 21h
  inc si
loop print_for       
       
mov ax, 4c00h ; Return 0
int 21h
ret




