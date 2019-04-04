data segment
   x db ?
   y db ?
   result db ?
   msgx db 10,13,"Enter the value of x:$"    
   msgy db 10,13,"Enter the value of y:$"
   msgr db 10,13,"The result is :$"
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
        print msgx
        input
        mov x, al
        print msgy
        input     
        mov y, al
        mov cl, y
        mov al, 01
   top: mul x
        loop top 
        mov bl,al
        print msgr
        printno bl
        
mov ax, 4c00h
int 21h  

ends

end start
