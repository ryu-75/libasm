extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text
global ft_strdup	; char *ft_strdup(const char *s)
ft_strdup:
	call ft_strlen 	; Call ft_strlen, that saves the length in rax
	push rdi		; Push rdi (that contain *s)
	inc rax			; Increment by 1 (for the null-terminator)
	mov rdi, rax	; move the length (rax) to rdi
	call malloc	wrt ..plt	; call malloc
	test rax, rax	; verify if calloc return  -1
	jz err			; err if -1
	pop rsi			; Pop *s from the stack to rsi (2nd arguments of ft_strcpy)
	mov rdi, rax    ; move the allocated memory to rdi (1st argument of ft_strcpy)
	call ft_strcpy	; call strcpy, copy rdi to rax
	jmp end				; return rax

err:
	mov rbx, rax		; set rax to -1 if malloc return -1
	call __errno_location wrt ..plt
	mov [rax], rbx
	neg dword [rax]
	mov rax, -1

end:
	ret