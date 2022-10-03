; Make an strchr in asm assembly language
; IL N'EST PAS ENCORE FINI !!!!!!!!!!!!!!!!!!!!
bits 64

    global strchr:

    section .text

strchr:
    mov rax, 0              ; init rax to 0

loop1:
    cmp byte[rdi], 0        ; compare if [rdi] == '\0'
    je isnull               ; if yes go to endstrchr
    cmp byte[rdi], sil      ; compare if [rdi] == char -> charactere past as parameter
    je copy                 ; if yes go to part copy
    inc rdi                 ; increment rdi +1
    jmp loop1               ; re lunch the loop1


isnull:
    cmp sil, 0
    je endtest
    mov rax, 0
    ret

copy:
    add rax, rdi            ; copy rest of rdi in rax
    jmp endstrchr           ; go to the endstrchr

endtest:
    add rax, rdi
    ret

endstrchr:
    ret                     ; return rax