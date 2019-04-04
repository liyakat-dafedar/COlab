data segment   
    ;a db 7 dup(0) 
    a db 01h, 02h, 03h, 04h, 03h
    t db ?
    ;msg db "Enter the number of tems that you want to enter:$"
    ;msgno db "Enter a number:$"    
    msge db 10,13,"The sum of even no:$"     
    msgo db 10,13,"The sum of odd no:$"
ends
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

code segment
start:   
        mov ax, data
        mov ds, ax 
        lea si, a
        mov cl, 05 
        mov bl,00h
        mov dl, 00h
    top:mov al, [si]
        shr al, 01
        jc odd
        add bl,[si]
        inc si
        loop top
    odd:add dl,[si]
        inc si
        loop top
        print msge
        printno bl
        print msgo
        printno dl

mov ax, 4c00h
int 21h  

ends

end start
