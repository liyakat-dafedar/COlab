data segment
    a db 5
    b db 3
    diff db ?
ends


code segment
start: 
    mov ax, data
    mov ds, ax
    xor ax, ax
    mov al, a
    sub al, b
    mov diff, al


mov ax, 4c00h
int 21h  

code ends

end start
