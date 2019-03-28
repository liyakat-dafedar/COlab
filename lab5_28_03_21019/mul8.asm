data segment
    a db 5
    b db 3
    product db ?
ends

code segment
start: 
    mov ax, data
    mov ds, ax
    xor ax, ax
    mov al, a
    mul b
    mov product, al
mov ax, 4c00h
int 21h  

code ends

end start