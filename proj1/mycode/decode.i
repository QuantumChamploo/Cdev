	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_swapLetter             ## -- Begin function swapLetter
	.p2align	4, 0x90
_swapLetter:                            ## @swapLetter
	.cfi_startproc
## BB#0:
	pushl	%ebp
Lcfi0:
	.cfi_def_cfa_offset 8
Lcfi1:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
Lcfi2:
	.cfi_def_cfa_register %ebp
	pushl	%ebx
	subl	$24, %esp
Lcfi3:
	.cfi_offset %ebx, -12
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movb	(%edx), %bl
	movb	%bl, -6(%ebp)
	movsbl	-6(%ebp), %edx
	movl	%edx, -12(%ebp)
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, -16(%ebp)
	movsbl	-6(%ebp), %edx
	cmpl	$46, %edx
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%ecx, -28(%ebp)         ## 4-byte Spill
	je	LBB0_13
## BB#1:
	movsbl	-6(%ebp), %eax
	cmpl	$33, %eax
	je	LBB0_13
## BB#2:
	movsbl	-6(%ebp), %eax
	cmpl	$44, %eax
	je	LBB0_13
## BB#3:
	movsbl	-6(%ebp), %eax
	cmpl	$63, %eax
	je	LBB0_13
## BB#4:
	movsbl	-6(%ebp), %eax
	cmpl	$59, %eax
	je	LBB0_13
## BB#5:
	movsbl	-6(%ebp), %eax
	cmpl	$32, %eax
	je	LBB0_13
## BB#6:
	movl	-12(%ebp), %eax
	subl	$96, %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%ebp)
	jge	LBB0_9
## BB#8:                                ##   in Loop: Header=BB0_7 Depth=1
	movl	-12(%ebp), %eax
	addl	$26, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_9:
	jmp	LBB0_10
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$26, -12(%ebp)
	jle	LBB0_12
## BB#11:                               ##   in Loop: Header=BB0_10 Depth=1
	movl	-12(%ebp), %eax
	subl	$26, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_10
LBB0_12:
	movl	-12(%ebp), %eax
	addl	$96, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	%al, %cl
	movb	%cl, -17(%ebp)
	movb	-17(%ebp), %cl
	movb	%cl, -5(%ebp)
	jmp	LBB0_14
LBB0_13:
	movb	-6(%ebp), %al
	movb	%al, -5(%ebp)
LBB0_14:
	movsbl	-5(%ebp), %eax
	addl	$24, %esp
	popl	%ebx
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_decodeMes              ## -- Begin function decodeMes
	.p2align	4, 0x90
_decodeMes:                             ## @decodeMes
	.cfi_startproc
## BB#0:
	pushl	%ebp
Lcfi4:
	.cfi_def_cfa_offset 8
Lcfi5:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
Lcfi6:
	.cfi_def_cfa_register %ebp
	pushl	%esi
	subl	$36, %esp
Lcfi7:
	.cfi_offset %esi, -12
	calll	L1$pb
L1$pb:
	popl	%eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	leal	L_.str-L1$pb(%eax), %eax
	movl	12(%ebp), %esi
	movl	%esi, -8(%ebp)
	movl	-8(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, -16(%ebp)         ## 4-byte Spill
	movl	%ecx, -20(%ebp)         ## 4-byte Spill
	calll	_printf
	movl	$0, -12(%ebp)
	movl	%eax, -24(%ebp)         ## 4-byte Spill
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-12(%ebp), %eax
	movl	-8(%ebp), %ecx
	movl	%esp, %edx
	movl	%ecx, (%edx)
	movl	%eax, -28(%ebp)         ## 4-byte Spill
	calll	_strlen
	movl	-28(%ebp), %ecx         ## 4-byte Reload
	cmpl	%eax, %ecx
	jae	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	8(%ebp), %eax
	movl	-8(%ebp), %ecx
	addl	-12(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_swapLetter
	movl	-8(%ebp), %ecx
	movl	-12(%ebp), %edx
	movb	%al, (%ecx,%edx)
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB1_1
LBB1_4:
	movl	-8(%ebp), %eax
	addl	$36, %esp
	popl	%esi
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushl	%ebp
Lcfi8:
	.cfi_def_cfa_offset 8
Lcfi9:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
Lcfi10:
	.cfi_def_cfa_register %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$60, %esp
Lcfi11:
	.cfi_offset %esi, -20
Lcfi12:
	.cfi_offset %edi, -16
Lcfi13:
	.cfi_offset %ebx, -12
	calll	L2$pb
L2$pb:
	popl	%eax
	leal	L_.str.1-L2$pb(%eax), %ecx
	movl	L___stack_chk_guard$non_lazy_ptr-L2$pb(%eax), %edx
	movl	(%edx), %edx
	movl	%edx, -16(%ebp)
	movl	$0, -36(%ebp)
	movl	$1, -40(%ebp)
	movb	$97, -41(%ebp)
	movsbl	-41(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -48(%ebp)         ## 4-byte Spill
	calll	_printf
	leal	-40(%ebp), %ecx
	leal	-41(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -52(%ebp)         ## 4-byte Spill
	calll	_swapLetter
	movl	-48(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str.2-L2$pb(%ecx), %edx
	movsbl	%al, %esi
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	calll	_printf
	movl	-48(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str.3-L2$pb(%ecx), %edx
	leal	-30(%ebp), %esi
	movl	L_main.str1-L2$pb(%ecx), %edi
	movl	%edi, -30(%ebp)
	movl	(L_main.str1-L2$pb)+4(%ecx), %edi
	movl	%edi, -26(%ebp)
	movl	(L_main.str1-L2$pb)+8(%ecx), %edi
	movl	%edi, -22(%ebp)
	movw	(L_main.str1-L2$pb)+12(%ecx), %bx
	movw	%bx, -18(%ebp)
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, -56(%ebp)         ## 4-byte Spill
	calll	_printf
	leal	-40(%ebp), %ecx
	leal	-30(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -60(%ebp)         ## 4-byte Spill
	calll	_decodeMes
	movl	-48(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str.4-L2$pb(%ecx), %edx
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	calll	_printf
	movl	-48(%ebp), %ecx         ## 4-byte Reload
	movl	L___stack_chk_guard$non_lazy_ptr-L2$pb(%ecx), %edx
	movl	(%edx), %edx
	movl	-16(%ebp), %esi
	cmpl	%esi, %edx
	movl	%eax, -64(%ebp)         ## 4-byte Spill
	jne	LBB2_2
## BB#1:
	xorl	%eax, %eax
	addl	$60, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
LBB2_2:
	calll	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"the message is %s\n"

L_.str.1:                               ## @.str.1
	.asciz	"the character is %c\n"

L_.str.2:                               ## @.str.2
	.asciz	"the next character is %c\n"

L_main.str1:                            ## @main.str1
	.asciz	"test string?!"

L_.str.3:                               ## @.str.3
	.asciz	"the test string is %s\n"

L_.str.4:                               ## @.str.4
	.asciz	"the decoded message is %s\n"


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols
