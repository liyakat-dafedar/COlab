data segment
    a dw 2
    b dw 3
    sum dw ?
ends

code segment
start: 
    mov ax, data
    mov ds, ax
    xor ax, ax
    mov ax, a
    add ax, b
    mov sum, ax


mov ax, 4c00h
int 21h  

code ends

end start
