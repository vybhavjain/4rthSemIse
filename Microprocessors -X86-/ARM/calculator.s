.text
.global start
start:
	mov r0,#0
	bl getdig
	mov r6,r2 ; first operand
	mov r0,#3
	mov r1,#2
	swi 0x205
	
	mov r0,#0
	bl getop
	mov r0,#6
	mov r1,#2
	cmp r7,#2
	ldrlt r2,=op1	;r2:operator
	ldreq r2,=op2
	cmp r7,#3
	ldreq r2,=op3
	ldrgt r2,=op5
	swi 0x204
	
	mov r0,#0
	bl getdig
	mov r8,r2	;r8:second operand
	mov r0,#9
	mov r1,#2
	swi 0x205

	mov r0,#0
wait:
	swi 0x203
	cmp r0,#0
	beq wait
	cmp r7,#2
	addlt r9,r6,r8
	beq sub
	cmp r7,#3
	muleq r9,r6,r8	;r9:result
	bgt division


back:	mov r0,#12
	mov r1,#2
	ldr r2,=op4
	swi 0x204
	cmp r5,#1
	beq printdiff
	mov r0,#16
	mov r2,r9
	swi 0x205	
	
	swi 0x11
getdig:
	swi 0x203
	cmp r0,#0
	beq getdig
	clz r0,r0
	rsb r0,r0,#31
	mov r2,r0
	mov pc,lr
	
getop:
	swi 0x203
	cmp r0,#0
	beq getop
	cmp r0,#2
	moveq r7,#2
	movlt r7,#1
	cmp r0,#3
	moveq r7,#3
	movgt r7,#4
	mov pc,lr
sub:    cmp r8,r6
	bgt rsub
	sub r9,r6,r8
	b back
	
rsub:	mov r5,#1
	sub r9,r8,r6
	b back

printdiff:  mov r0,#15
	    ldr r2,=op2
	    swi 0x204
	    mov r2,r9
	    mov r0,#16
	   swi 0x205
	    swi 0x11

division:  mov r10,#0
	mov r11,r6
cmpo:	cmp r11,r8
	blt back
	sub r11,r11,r8
	add r10,r10,#1
	mov r9,r10
	b cmpo
	

.data:
	op1: .asciz "+"
	op2: .asciz "-"
	op3: .asciz "*"
	op5: .asciz "/"
	op4: .asciz "="
.end
