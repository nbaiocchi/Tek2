; Make an strlen in asm assembly language

bits 64

    global strstr:

    section .text

strstr:
    mov rax, 0
    mov rbx, 0

loop:
    cmp BYTE[rdi], 0
    je end_null
    jmp check_str

check_str:
    mov r10b, BYTE [rdi+rbx]
	mov r11b, BYTE [rsi+rbx]
    cmp r11b, 0
    je endstrstr
    cmp r10b, r11b
    jne return_to
    inc rbx
    jmp check_str

return_to:
    mov rbx, 0
    inc rdi
    jmp loop

end_null:
    mov rax, 0
    ret

endstrstr:
    add rax, rdi
    ret