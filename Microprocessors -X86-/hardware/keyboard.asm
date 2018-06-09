assume cs:code,ds:data
data segment
  pa equ 20a0h
  pb equ 20a1h
  pc equ 20a2h
  cr equ 20a3h
  rowval db ?
  colval db ?
  scode db ?
data ends

code segment
start:
        mov ax,data
        mov ds,ax
        mov dx,cr
        mov al,90h
        out dx,al
tryagain:
        mov bl,01h
        mov bh,03h
        mov cl,00h
next_row:
        mov dx,pc
        mov al,bl
        out dx,al

        mov dx,pa
        in al,dx

        cmp al,00h
        jne calculate
        add cl,08h
        inc ah
        shl bl,01
        dec bh
        jnz next_row
        jmp tryagain
calculate:
        mov rowval,ah
        mov ah,00h
rot_again:
        ror al,01
        jc next
        inc ah
        inc cl
        jmp rot_again
next:
        mov scode,cl
        mov colval,ah
        mov al,cl
        call disp
        mov ah,4ch
        int 21h

disp proc
        mov bl,al
        mov cl,4
        shr al,cl
        cmp al,09
        jle add_30
        add al,07

add_30:
        add al,30h
        mov dl,al
        mov ah,02
        int 21h
        mov al,bl
        and al,0fh
        cmp al,09
        jle add_30_1
        add al,07
add_30_1:
        add al,30h
        mov dl,al
        mov ah,02
        int 21h
        ret

disp endp
code ends
end start
