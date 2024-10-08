global ft_strcpy                ; ft_strcpy(char *dest, const char *src)

ft_strcpy:
    xor rcx, rcx                ; Initialize rcx to 0, this will be our counter

.loop:
    mov al, [rsi + rcx]        ; move the byte from [rsi + rcx] to al - rsi is our 2nd parameter (src)
    mov [rdi + rcx], al        ; move al to [rdi + rcx] - rdi is our 1st parameter (dest)
    test al, al               ; AND operator if al is equal to 0 and set FLAG_ZERO (FZ) - null terminator
    je .end                     ; Jump to .end if al is equal to 0
    inc rcx                     ; Increment rcx to move to the next byte
    jmp .loop                   ; Return the loop

.end:
    mov rax, rdi                ; Move the destination pointer [rdi] to rax as the return value
    ret                         ; return from the function
