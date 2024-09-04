extern __errno_location
global ft_write                 ; ssize_t write(int fd, const void buf, size_t count)

ft_write:
    mov rax, 1                  ; Syscall number for sys_write
    syscall                     ; Perform the syscall

    test rax, rax              ; Test if the return value (rax) is negative
    js  err                     ; Jump to error handling if flag sign is set (negative value)
    ret                         ; Return is no error

err:
    neg rax                     ; Convert the regative value to a positive error code
    mov rdi, rax                ; Move the error code to rdi register (for errno_location call)
    call __errno_location       ; Call errno_location
    mov [rax], rdi              ; Move the error code from rdi to rax reference which is errno now
    mov rax, -1                 ; Return -1 for indicate an error
    ret                         ; Return the error code
