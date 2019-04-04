data segment
abc dd 12345678h
def dd 9ABCDEF0h
ghi dw ?
data ends
 
code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
mov dl,00h
mov ax, word ptr abc
mov bx, word ptr def
add ax,bx
mov word ptr ghi,ax
mov ax, word ptr abc+2
mov bx, word ptr def+2
adc ax,bx
mov word ptr ghi+2,ax
jnc move
inc dl
move: mov byte ptr ghi+4,dl     
mov ah, 4ch
int 21h
code ends
end start