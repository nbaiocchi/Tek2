; Make an strlen in asm assembly languagebits 64

    global strpbrk:

    section .text

strpbrk:
    mov rax, 0              ; init rax to 0
    mov rbx, 0

loop:
    cmp byte[rdi], 0        ; compare if [rdi] == '\0'
    je isnull
    jmp checkchar
    

checkchar:
    mov r10b, BYTE [rdi]
	mov r11b, BYTE [rsi+rbx]
    cmp r11b, 0
    je return_loop
    cmp r10b, r11b
    je copy
    inc rbx
    jmp checkchar

return_loop:
    mov rbx, 0
    inc rdi
    jmp loop

isnull:
    mov rax, 0
    ret

copy:
    mov rax, rdi            ; copy rest of rdi in rax
    ret