;write alp to  compute factorial of a number
;write an alp to compute x ^Y
;write an alp to find the sum of even and odd numbers in an array
;write ann alp to find an average of  two numbers

data segment
   n db ?
   fact dw 01h  
   t db 10
   msg db "Enter a number:$"
   msgr db 10,13"The factorial of the entered number is $"
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
start:  mov ax, data
        mov ds, ax
        xor ax, ax
        print msg
        input
        mov cl, al
        mov al, 01h
   top: mul cl
        loop top 
        mov ah, 0
        div t 
        mov bl,al
        mov bh, ah
        ;cmp al,00h
        ;jnz top1
        ;printno al

	print msgr
   top1:printno bl
        printno bh
         



mov ax, 4c00h
int 21h  

ends

end start
