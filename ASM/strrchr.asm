; Make an strrchr in asm assembly language
; IL N'EST PAS ENCORE FINI !!!!!!!!!!!!!!!!!!!!
bits 64

    global strrchr:

    section .text

strrchr:
    mov rax, 0              ; init rax to 0

loop1:
    cmp byte[rdi], 0        ; compare if [rdi] == '\0'
    je isnull            ; if yes go to endstrrchr
    cmp byte[rdi], sil      ; compare if [rdi] == char -> charactere past as parameter
    je copy                 ; if yes go to part copy
    inc rdi                 ; increment rdi +1
    jmp loop1               ; re lunch the loop1

copy:
    mov rax, rdi            ; copy rest of rdi in rax
    inc rdi                 ; increment rdi +1
    jmp loop1               ; re lunch the loop1

isnull:
    cmp sil, 0
    je endtest
    ret

endtest:
    mov rax, rdi
    ret