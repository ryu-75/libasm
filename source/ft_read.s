extern __errno_location

section .text
global ft_read
ft_read:                    ; ssize_t   ft_read(int fd, void *buf, size_t count);
    mov rax, 0              ; Set rax with sys_read parameters
    syscall

    test rax, rax           ; Check if rax return 0
    js err                 ; If -1 return an error
    jmp end                     ; Return rax

err:
    mov rbx, rax                ; Move the error code to rdi register (for errno_location call)
    call __errno_location wrt ..plt ; Call errno_location
    mov [rax], rbx              ; Move the error code from rdi to rax reference which is errno now
    neg dword [rax]
    mov rax, -1                 ; Return -1 for indicate an error

end:
    ret