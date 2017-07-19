	.file "test4.c"
 	.text
  	.align 2
.globl main
	.type main,@function
main:
.LFB2:
	pushl %ebp
.LCFI0:
        movl %esp, %ebp
.LCFI1:
        subl $88, %esp
.LCFI2:
        andl $-16, %esp
        movl $0, %eax
	subl %eax, %esp
	movl $197, -12(%ebp) # a = 197
	cmpl $99, -12(%ebp) # compare a and 99
	jg .L2 # if a greater then goto .L2
	movl $134, -16(%ebp) # b = 134
	jmp .L3 # goto .L3
.L2:
	movl $26, -16(%ebp) # b = 26
.L3: 		movl $0, -76(%ebp) # i = 0
.L4:
	cmpl $2, -76(%ebp)# compare i and 2
	jle .L7 # if i <= 2 goto .L7
	jmp .L5 # goto .L5
.L7:
	movl -76(%ebp), %edx # edx = i
	movl -16(%ebp), %eax # eax = b
	addl -12(%ebp), %eax # eax += a
	movl %eax, -72(%ebp,%edx,4)
	leal -76(%ebp), %eax # eax = &i
	incl (%eax) # i++
	jmp .L4
.L5:
	movl -52(%ebp), %eax # eax = c[5]
	addl $18, %eax # eax += 18
	movl %eax, -12(%ebp) # a = eax
	movl -16(%ebp), %eax # return b
	leave
	ret
.LFE2:
.Lfe1:
	.size main,.Lfe1-main
	.section 	.note.GNU-stack,"",@progbits
	.ident "GCC: (GNU) 3.2.3 20030502 (Red Hat
Linux 3.2.3-49)"
