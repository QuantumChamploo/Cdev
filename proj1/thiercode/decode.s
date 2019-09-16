	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$56, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	$0, -4(%ebp)
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	movl	%ecx, -24(%ebp)         ## 4-byte Spill
	movl	%edx, -28(%ebp)         ## 4-byte Spill
	calll	_read_cipher_file
	movl	-20(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str-L0$pb(%ecx), %edx
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	calll	_printf
	movl	%eax, -32(%ebp)         ## 4-byte Spill
	calll	_get_login_key
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_decode
	movl	-20(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str.1-L0$pb(%ecx), %edx
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	calll	_printf
	xorl	%ecx, %ecx
	movl	%eax, -36(%ebp)         ## 4-byte Spill
	movl	%ecx, %eax
	addl	$56, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_decode                 ## -- Begin function decode
	.p2align	4, 0x90
_decode:                                ## @decode
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset %ebx, -12
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%ecx, -28(%ebp)         ## 4-byte Spill
	calll	_calculate_shifts
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-12(%ebp), %eax
	movsbl	(%eax), %eax
	cmpl	$0, %eax
	je	LBB1_7
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	movsbl	(%eax), %eax
	cmpl	$97, %eax
	jl	LBB1_4
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	movsbl	(%eax), %eax
	cmpl	$122, %eax
	jle	LBB1_5
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_6
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	movsbl	(%eax), %eax
	subl	$97, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	addl	-8(%ebp), %eax
	cltd
	movl	$26, %ecx
	idivl	%ecx
	movl	%edx, -20(%ebp)
	movl	-20(%ebp), %ecx
	addl	$97, %ecx
	movb	%cl, %bl
	movl	-12(%ebp), %ecx
	movb	%bl, (%ecx)
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB1_1
LBB1_7:
	movl	8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_read_cipher_file       ## -- Begin function read_cipher_file
	.p2align	4, 0x90
_read_cipher_file:                      ## @read_cipher_file
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	pushl	%esi
	subl	$36, %esp
	.cfi_offset %esi, -12
	calll	L2$pb
L2$pb:
	popl	%eax
	leal	L_.str.2-L2$pb(%eax), %ecx
	leal	L_.str.3-L2$pb(%eax), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	calll	_fopen$UNIX2003
	movl	%eax, -8(%ebp)
	cmpl	$0, -8(%ebp)
	jne	LBB2_2
## %bb.1:
	movl	-20(%ebp), %eax         ## 4-byte Reload
	movl	L___stderrp$non_lazy_ptr-L2$pb(%eax), %ecx
	movl	(%ecx), %ecx
	leal	L_.str.4-L2$pb(%eax), %edx
	movl	%esp, %esi
	movl	%edx, 4(%esi)
	movl	%ecx, (%esi)
	calll	_fprintf
	movl	%esp, %ecx
	movl	$1, (%ecx)
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	calll	_exit
LBB2_2:
	movl	$1000, (%esp)           ## imm = 0x3E8
	calll	_malloc
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	-8(%ebp), %ecx
	movl	%eax, (%esp)
	movl	$1000, 4(%esp)          ## imm = 0x3E8
	movl	%ecx, 8(%esp)
	calll	_fgets
	cmpl	$0, %eax
	jne	LBB2_4
## %bb.3:
	movl	-20(%ebp), %eax         ## 4-byte Reload
	movl	L___stderrp$non_lazy_ptr-L2$pb(%eax), %ecx
	movl	(%ecx), %ecx
	leal	L_.str.5-L2$pb(%eax), %edx
	movl	%esp, %esi
	movl	%edx, 4(%esi)
	movl	%ecx, (%esi)
	calll	_fprintf
	movl	%esp, %ecx
	movl	$1, (%ecx)
	movl	%eax, -28(%ebp)         ## 4-byte Spill
	calll	_exit
LBB2_4:
	movl	-12(%ebp), %eax
	movl	%esp, %ecx
	movl	%eax, (%ecx)
	calll	_strlen
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %ecx
	subl	$1, %ecx
	movsbl	(%eax,%ecx), %eax
	cmpl	$10, %eax
	jne	LBB2_6
## %bb.5:
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %ecx
	subl	$1, %ecx
	movb	$0, (%eax,%ecx)
LBB2_6:
	movl	-12(%ebp), %eax
	addl	$36, %esp
	popl	%esi
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_get_login_key          ## -- Begin function get_login_key
	.p2align	4, 0x90
_get_login_key:                         ## @get_login_key
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	pushl	%esi
	subl	$36, %esp
	.cfi_offset %esi, -12
	calll	L3$pb
L3$pb:
	popl	%eax
	movl	$50, (%esp)
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	calll	_malloc
	movl	-16(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str.6-L3$pb(%ecx), %edx
	movl	%eax, -8(%ebp)
	movl	%edx, (%esp)
	calll	_printf
	movl	-16(%ebp), %ecx         ## 4-byte Reload
	movl	L___stdinp$non_lazy_ptr-L3$pb(%ecx), %edx
	movl	-8(%ebp), %esi
	movl	(%edx), %edx
	movl	%esi, (%esp)
	movl	$50, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	calll	_fgets
	cmpl	$0, %eax
	jne	LBB3_2
## %bb.1:
	movl	-16(%ebp), %eax         ## 4-byte Reload
	movl	L___stderrp$non_lazy_ptr-L3$pb(%eax), %ecx
	movl	(%ecx), %ecx
	leal	L_.str.7-L3$pb(%eax), %edx
	movl	%esp, %esi
	movl	%edx, 4(%esi)
	movl	%ecx, (%esi)
	calll	_fprintf
	movl	%esp, %ecx
	movl	$1, (%ecx)
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	calll	_exit
LBB3_2:
	movl	-8(%ebp), %eax
	movl	%esp, %ecx
	movl	%eax, (%ecx)
	calll	_strlen
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	subl	$1, %ecx
	movsbl	(%eax,%ecx), %eax
	cmpl	$10, %eax
	jne	LBB3_4
## %bb.3:
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	subl	$1, %ecx
	movb	$0, (%eax,%ecx)
LBB3_4:
	movl	-8(%ebp), %eax
	addl	$36, %esp
	popl	%esi
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_calculate_shifts       ## -- Begin function calculate_shifts
	.p2align	4, 0x90
_calculate_shifts:                      ## @calculate_shifts
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, -4(%ebp)
	movl	$0, -8(%ebp)
	movl	%eax, -12(%ebp)         ## 4-byte Spill
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4(%ebp), %eax
	movsbl	(%eax), %eax
	cmpl	$0, %eax
	je	LBB4_4
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %ecx
	movsbl	(%ecx), %ecx
	xorl	%ecx, %eax
	movl	%eax, -8(%ebp)
## %bb.3:                               ##   in Loop: Header=BB4_1 Depth=1
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	LBB4_1
LBB4_4:
	movl	-8(%ebp), %eax
	cltd
	movl	$26, %ecx
	idivl	%ecx
	movl	%edx, (%esp)
	calll	_abs
	movl	%eax, -8(%ebp)
	cmpl	$0, -8(%ebp)
	jne	LBB4_6
## %bb.5:
	movl	$1, -8(%ebp)
LBB4_6:
	movl	-8(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Ciphertext:\n%s\n"

L_.str.1:                               ## @.str.1
	.asciz	"Plaintext:\n%s\n"

L_.str.2:                               ## @.str.2
	.asciz	"ciphertext.txt"

L_.str.3:                               ## @.str.3
	.asciz	"r"

L_.str.4:                               ## @.str.4
	.asciz	"Cannot open file for reading.\n"

L_.str.5:                               ## @.str.5
	.asciz	"Error reading ciphertext file.\n"

L_.str.6:                               ## @.str.6
	.asciz	"Enter your CS login: "

L_.str.7:                               ## @.str.7
	.asciz	"Error reading user input.\n"


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stderrp$non_lazy_ptr:
	.indirect_symbol	___stderrp
	.long	0
L___stdinp$non_lazy_ptr:
	.indirect_symbol	___stdinp
	.long	0

.subsections_via_symbols
