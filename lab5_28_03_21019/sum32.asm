DATA SEGMENT
        A DD 090F0433H
        ;B DD 50H
        RES DD ?
DATA ENDS

CODE SEGMENT
ASSUME  DS:DATA, CS:CODE
START:
        MOV AX,DATA
        MOV DS,AX

        MOV AX,DS:WORD PTR A
        ;ADC AX,DS:WORD PTR B
        MOV BX,DS:WORD PTR A+2
        ;ADD BX,DS:WORD PTR [B+2]
        MOV DS:WORD PTR RES,AX    
         ;MOV DS:WORD PTR B,BX
        ;MOV DS:WORD PTR [RES+2],BX

        MOV AX,4CH
        INT 21H

CODE ENDS
END START