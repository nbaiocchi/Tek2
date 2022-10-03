; Make an strlen in asm assembly language
bits 64

    global memcpy:

    section .text

memcpy:
    mov rax, 0
    mov rbx, 0

loop:
    cmp rbx, rdx
    je endmemcpy
    mov r10b, BYTE[rsi+rbx]
    mov BYTE[rdi+rbx], r10b
    inc rbx
    jmp loop

endmemcpy:
    add rax, rdi
    ret