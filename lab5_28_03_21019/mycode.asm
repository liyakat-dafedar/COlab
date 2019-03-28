data segment
sum1 dw 0 
sum 2 dw 0
n1 dd 0FFFFFFFFh
n2 dd 0FFFFFFFFh

ends

code segment
start:

   
mov ax, word ptr [n1]
mov bx, word ptr [n1+2]
mov cx, word ptr [n2]
mov dx, word ptr [n2+2]
add ax, cx
adc bx, dx
mov  sum1,ax 
mov  sum2, bx


mov ax, 4c00h
int 21h  

ends

end start
