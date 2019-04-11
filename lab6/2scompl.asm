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
    A db ?
    comp db ?
ends

code segment
start:    
        mov ax, data
        mov ds, ax
        xor ax, ax
        input 
        mov A, al
        not A
        inc A
        ;mov al, A 
        ;mov bl, 10
        ;div bl
        ;aam 
        mov ah, 00h
        print A
mov ax, 4c00h
int 21h  

ends

end start
