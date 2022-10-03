; Make an strlen in asm assembly language
bits 64

    global memset:

    section .text

memset:
    mov rax, 0

loop:
    cmp rax, rdx
    je endstrlen
    mov byte[rdi+rax], sil
    inc rax
    jmp loop

endstrlen:
    mov rax, rdi
    ret