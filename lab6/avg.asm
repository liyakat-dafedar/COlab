data segment
   x db ?
   y db ?
   result db ?
   msgx db 10,13,"Enter the first value :$"    
   msgy db 10,13,"Enter the second value :$"
   msgr db 10,13,"The average is :$"
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
	mov al, x
	add al, y
	mov bl, 02h
	div bl
	
        mov result, al
        print msgr
        printno result
        
mov ax, 4c00h
int 21h  

ends

end start
