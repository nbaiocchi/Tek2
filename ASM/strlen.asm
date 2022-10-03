; Make an strlen in asm assembly language
bits 64

    global strlen:

    section .text

strlen:
    mov rax, 0              ; initialise rax to 0

loop:
    cmp byte[rdi+rax], 0    ; check if [rdi] == '\0'
    je endstrlen            ; go to endstrlen
    inc rax                 ; increment rax +1
    jmp loop                ; re lunch the loop

endstrlen:
    ret                     ; return rax