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
    L db ?
    msgenter db 10,13,"Enter the number of terms$"
    msgno db 10,13,"Enter the numbers$"
    largest db 10,13,"Largest No:$"
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
        lea si, A 
        mov al, [si]
        mov L, al
        mov cl, N
        dec cl 
  top1: inc si
        mov al, [si]
        cmp L, al
        jc top2 
        cmp cl, 00h
        jz exit
        loop top1
        jmp exit
  top2: mov al, [si]
        mov L, al  
        cmp cl, 00h
        jz exit
  top3: loop top1
        
 exit:  print largest  
        printno L

mov ax, 4c00h
int 21h  

ends

end start
