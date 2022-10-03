; Make an strlen in asm assembly language

bits 64

    global strcasecmp:

    section .text

strcasecmp:
    mov rax, 0
    mov rbx, 0

loop:
    mov r10b, BYTE [rdi]
	mov r11b, BYTE [rsi]
    cmp r10b, 0
    je checkend_f
    cmp r11b, 0
    je checkend_s

is_maj:
    cmp r10b, 96
    jge decr
    jmp is_maj2

decr:
    sub r10b, 32
    jmp is_maj2

is_maj2:
    cmp r11b, 96
    jge decr2
    cmp r10b, r11b
    jne check_first
    inc rdi
    inc rsi
    jmp loop

decr2:
    sub r11b, 32
    cmp r10b, r11b
    jne check_first
    inc rdi
    inc rsi
    jmp loop

checkend_f:
    cmp r11b, 0
    jmp endtrue

checkend_s:
    cmp r10b, 0
    jmp endtrue

check_first:
    movsx rax, r10b
    movsx rbx, r11b
    sub rax, rbx
    ret

endtrue:
    mov rax, 0
    ret