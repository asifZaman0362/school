	.text
	.file	"asm.c"
	.globl	main                    // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
// %bb.0:
	sub	sp, sp, #32             // =32
	stp	x29, x30, [sp, #16]     // 16-byte Folded Spill
	add	x29, sp, #16            // =16
	adrp	x0, .L.str
	add	x0, x0, :lo12:.L.str
	sub	x1, x29, #4             // =4
	add	x2, sp, #8              // =8
	bl	scanf
	ldur	w8, [x29, #-4]
	ldr	w9, [sp, #8]
	cmp	w8, w9
	b.ne	.LBB0_2
// %bb.1:
	adrp	x0, .L.str.1
	add	x0, x0, :lo12:.L.str.1
	bl	printf
	b	.LBB0_3
.LBB0_2:
	adrp	x0, .L.str.2
	add	x0, x0, :lo12:.L.str.2
	bl	printf
.LBB0_3:
	ldp	x29, x30, [sp, #16]     // 16-byte Folded Reload
	add	sp, sp, #32             // =32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        // -- End function
	.type	.L.str,@object          // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d%d"
	.size	.L.str, 5

	.type	.L.str.1,@object        // @.str.1
.L.str.1:
	.asciz	"Equal"
	.size	.L.str.1, 6

	.type	.L.str.2,@object        // @.str.2
.L.str.2:
	.asciz	"Not equal"
	.size	.L.str.2, 10

	.ident	"clang version 10.0.1 (https://github.com/termux/termux-packages 6c2f9eab313cd099ce3cb97038f4ec27735a742f)"
	.section	".note.GNU-stack","",@progbits
