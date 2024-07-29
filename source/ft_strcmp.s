; Reminder :
            ; movzx : It move a byte or word from one operand to a register, zero-extending the value to fill the destination register.

global ft_strcmp                ; int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
.loop:
    movzx rax, byte [rdi]           ; Load byte from memory at address in rdi into rax [64 bits], zero-extended
    movzx rbx, byte [rsi]           ; Load byte from memory at address in rsi into rbx [64 bits], zero-extended
    cmp rax, rbx                    ; Compare if rax and rbx
    jne .end                        ; If rax != rbx jump to .end
    test rax, rax                   ; Check if rax (and rbx, rax == rbx) is null
    je .end                         ; If null terminated is reached, jump to .end
    inc rdi                         ; increment rdi
    inc rsi                         ; increment rsi
    jmp .loop                       ; Repeat the loop

.end:
    sub rax, rbx                    ; Subtract rax from rax to get the difference
    ret                             ; Return the result