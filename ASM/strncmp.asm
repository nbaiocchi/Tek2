; Make an strlen in asm assembly language

bits 64

    global strncmp:

    section .text

strncmp:
    mov rax, 0
    mov rbx, 0
    mov rcx, 0


loop:
    mov r10b, BYTE [rdi]
	mov r11b, BYTE [rsi]
    cmp rcx, rdx
    je endtrue
    cmp r10b, 0
    je checkend_f
    cmp r11b, 0
    je checkend_s
    cmp r10b, r11b
    jne check_first
    inc rdi
    inc rsi
    inc rcx
    jmp loop

checkend_f:
    cmp r11b, 0
    jne check_first
    jmp endtrue

checkend_s:
    cmp r10b, 0
    jne check_first
    jmp endtrue

check_first:
    movsx rax, r10b
    movsx rbx, r11b
    sub rax, rbx
    ret

endtrue:
    mov rax, 0
    ret

    ; string vide