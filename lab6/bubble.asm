print macro arg
    lea dx, arg
    mov ah, 09h 
    int 21h
endm 
input macro 
    mov ah,01h
    int 21h
    sub al, 30h
endm
printno macro arg
    mov dl, arg 
    add dl, 30h
    mov ah, 02h
    int 21h
endm 
data segment
    A db 10 dup(?)
    N db ?        
    
    msgenter db 10,13,"Enter the number of terms:$"
    msgno db 10,13,"Enter the numbers$"    
    msgsorted db 10,13,"Elements in sorted order:$"
ends

code segment
start:
      mov ax, data
      mov ds, ax
      print msgenter
      xor ax, ax
      input
      mov N, al
      mov cl, N 
      print msgno
      lea si, A
  top:  input 
        mov [si], al
        inc si
        loop top 
        mov bl, N
        dec bl
top3:   mov cl, N
        dec cl
        lea si, A
top1:   
        mov al, [si]
        inc si
        cmp al, [si]
        jc top2
        jmp lp
   top2:xchg al, [si]
        dec si
        mov [si], al
        inc si    
    lp: loop top1
        dec bl  
        sub bl, 00h
        jnz top3
        print msgsorted
        lea si, A
        mov cl, N
  top5:  printno [si] 
        inc si
        loop top5 
        
mov ax, 4c00h
int 21h  

ends

end start