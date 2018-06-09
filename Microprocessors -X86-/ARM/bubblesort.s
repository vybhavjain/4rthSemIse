.text
.global _start
_start:


mov r0, #9
mov r10, #0
mov r11, #0
ldr r5, =arr
add r6, r5, #4
loop1: 
       ldr r5, =arr
       add r6, r5, #4
       mov r11, #0

loop2:
       ldr r8, [r5]
       ldr r9, [r6]
       cmp r8, r9
       movgt r3, r8
       movgt r8, r9
       movgt r9, r3
       str r8, [r5], #4
       str r9, [r6], #4
       add r11, r11, #1
       cmp r11, r0
       blt loop2

add r10, r10, #1
cmp r10, r0
blt loop1

.data
arr: .word 5,6,9,2,1,8,3,7,0              
