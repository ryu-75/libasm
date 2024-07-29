global ft_strlen 				; ft_strlen(const char *str)

ft_strlen:
	xor rcx, rcx					; Initialize rcx to 0, this will be our counter

.loop:
	mov al, byte [rdi + rcx]		; Load the byte at address [rdi + rcx] into al
	test al, al						; Perform a bitwise AND operation of `al` with itself to set the ZF flag 
	je .end							; If al is zero (end of string), jump to .end
	inc rcx							; Increment rcx
	jmp .loop						; Repeat the loop

.end:
	mov rax, rcx					; Move the count (rcx) to rax (return value)
	ret								; Return the result