data segment
    a dw 5
    b dw 3
    diff dw ?
ends

code segment
start: 
    mov ax, data
    mov ds, ax
    xor ax, ax
    mov ax, a
    sub ax, b
    mov diff, ax


mov ax, 4c00h
int 21h  

code ends

end start