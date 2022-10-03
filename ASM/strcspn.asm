; Make an strlen in asm assembly language
bits 64

    global strcspn:

    section .text

strcspn:
    mov rax, 0
    mov rbx, 0
    mov rcx, 0

loop:
    cmp byte[rdi+rax], 0
    je endstrcspn
    jmp checkchar

checkchar:
    mov r10b, BYTE [rdi+rax]
	mov r11b, BYTE [rsi+rbx]
    cmp r11b, 0
    je return_loop
    cmp r10b, r11b
    je endstrcspn
    inc rbx
    jmp checkchar

return_loop:
    mov rbx, 0
    inc rax
    jmp loop

endstrcspn:
    ret