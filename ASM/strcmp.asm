; Make an strlen in asm assembly language
bits 64

    global strcmp:

    section .text

strcmp:
    mov rax, 0
    mov rbx, 0

loop:
    mov r10b, BYTE [rdi]
	mov r11b, BYTE [rsi]
    cmp r10b, r11b
    jne check_first
    cmp r10b, 0
    je endtrue
    inc rdi
    inc rsi
    jmp loop

check_first:
    movsx rax, r10b
    movsx rbx, r11b
    cmp rax, rbx
    jge endfalse ; if rax > rbx jump to endfalse
    jmp endother

endtrue:
    ret

endfalse:
    mov rax, 1
    ret

endother:
    mov rax, -1
    ret


    ; verif les cas ou c pareil