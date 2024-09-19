extern __errno_location

section .text
global ft_write                 ; ssize_t write(int fd, const void buf, size_t count)
ft_write:
    mov rax, 1                  ; Syscall number for sys_write
    syscall                     ; Perform the syscall

    test rax, rax               ; Test if the return value (rax) is negative
    js err                      ; Jump if an error is returned
    jmp end                     

err:
    mov rbx, rax                   
    call __errno_location wrt ..plt
    mov [rax], rbx
    neg dword [rax]
    mov rax, -1

end:
    ret
