assume cs:code, ds:data

disp macro str3
    lea dx,str3
    mov ah,0Dh
    int 21h  
    mov ah,09h
    int 21h 
endm

data segment
     fname2 db "shashi.txt"
     msg1 db "File created successfully $" ;pass your own message to verify
     fname1 db "emp.dat"
     msg2 db "File deleted successfully$"  
data ends

code segment  
    start:
     mov ax,@data
     mov ds,ax

     mov ah,3ch
     mov cx,00
     lea dx,fname2
     int 21h
     disp msg1

     mov ah,41h
     lea dx,fname1
     int 21h
     disp msg2

     mov ah,4ch
     int 21h
code ends
end start
