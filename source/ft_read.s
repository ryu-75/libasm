extern __errno_location
global ft_read

ft_read:
    mov rax, 0          ; Set rax with sys_read parameters
    syscall           
    
    test rax, rax       ; Check if rax return 0
    jl  err             ; If -1 return an error
    ret                 ; Return rax

err:
    neg rax             
    mov rdi, [rax]
    call __errno_location
    mov rax, [rdi]
    mov rax, -1
    ret 
