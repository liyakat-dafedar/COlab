;write alp to  compute factorial of a number
;write an alp to compute x ^Y
;write an alp to find the sum of even and odd numbers in an array
;write ann alp to find an average of  two numbers

data segment
   n db ?
   fact dw 00h  
   t db 10
   msg db "Enter a number:$"
   msgr db 10,13,"The factorial of the entered number is $"                  
   msgf db 10,13,"Factorial:$"
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
        aam     
        xchg ah,al
        add ax,3030h
	    mov fact, ax 
	    print msgf
        print fact    
        xor ax, ax

mov ax, 4c00h
int 21h  

ends

end start
