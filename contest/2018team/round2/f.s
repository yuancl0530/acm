	.file	"f.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZL3mod, @object
	.size	_ZL3mod, 4
_ZL3mod:
	.long	1000000007
	.align 4
	.type	_ZL4maxn, @object
	.size	_ZL4maxn, 4
_ZL4maxn:
	.long	1000100
	.globl	dp
	.bss
	.align 32
	.type	dp, @object
	.size	dp, 102010000
dp:
	.zero	102010000
	.globl	a
	.align 32
	.type	a, @object
	.size	a, 20200
a:
	.zero	20200
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2075:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L10:
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	cmpl	$-1, %eax
	setne	%al
	testb	%al, %al
	je	.L2
	movl	$1, -28(%rbp)
.L4:
	movl	-36(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jg	.L3
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	$a, %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	addl	$1, -28(%rbp)
	jmp	.L4
.L3:
	movl	$1, -24(%rbp)
.L9:
	movl	-36(%rbp), %eax
	cmpl	%eax, -24(%rbp)
	jge	.L5
	movl	$1, -20(%rbp)
.L8:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%eax, %edx
	movl	-36(%rbp), %eax
	cmpl	%eax, %edx
	jg	.L6
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rdx
	movl	-16(%rbp), %eax
	cltq
	imulq	$5050, %rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	leaq	dp(%rax), %rdx
	movl	-16(%rbp), %eax
	leal	1(%rax), %esi
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movslq	%esi, %rax
	imulq	$5050, %rax, %rax
	addq	%rcx, %rax
	salq	$2, %rax
	addq	$dp, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$5050, %rcx, %rcx
	addq	%rcx, %rdx
	movl	%eax, dp(,%rdx,4)
	movl	-16(%rbp), %eax
	cltq
	movl	a(,%rax,4), %edx
	movl	-12(%rbp), %eax
	cltq
	movl	a(,%rax,4), %eax
	cmpl	%eax, %edx
	jne	.L7
	movl	-16(%rbp), %eax
	leal	1(%rax), %edx
	movl	-12(%rbp), %eax
	subl	$1, %eax
	cltq
	movslq	%edx, %rdx
	imulq	$5050, %rdx, %rdx
	addq	%rdx, %rax
	movl	dp(,%rax,4), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movl	-16(%rbp), %eax
	cltq
	imulq	$5050, %rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	leaq	dp(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZSt3maxIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$5050, %rcx, %rcx
	addq	%rcx, %rdx
	movl	%eax, dp(,%rdx,4)
.L7:
	addl	$1, -20(%rbp)
	jmp	.L8
.L6:
	addl	$1, -24(%rbp)
	jmp	.L9
.L5:
	movl	-36(%rbp), %eax
	cltq
	addq	$5050, %rax
	movl	dp(,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L2:
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L12
	call	__stack_chk_fail
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2075:
	.size	main, .-main
	.section	.text._ZSt3maxIiERKT_S2_S2_,"axG",@progbits,_ZSt3maxIiERKT_S2_S2_,comdat
	.weak	_ZSt3maxIiERKT_S2_S2_
	.type	_ZSt3maxIiERKT_S2_S2_, @function
_ZSt3maxIiERKT_S2_S2_:
.LFB2077:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L14
	movq	-16(%rbp), %rax
	jmp	.L15
.L14:
	movq	-8(%rbp), %rax
.L15:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2077:
	.size	_ZSt3maxIiERKT_S2_S2_, .-_ZSt3maxIiERKT_S2_S2_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2081:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L18
	cmpl	$65535, -8(%rbp)
	jne	.L18
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L18:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2081:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_dp, @function
_GLOBAL__sub_I_dp:
.LFB2082:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2082:
	.size	_GLOBAL__sub_I_dp, .-_GLOBAL__sub_I_dp
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_dp
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
