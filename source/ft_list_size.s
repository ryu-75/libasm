section .data
    struc node
        info resq 1
        next resq 1
    endstruc
    len: equ $ - node 

section .text
    global ft_lst_size

ft_lst_size:
    xor rcx, rcx

    push rbp
    mov rbp, rsp

    push rbx

    mov rbx, rdi

    cmp rbx, 0
    je nullpointer 

next_element:
    inc rcx
    mov rdx, [rdx + next]
    cmp rdx, 0
    jne next_element

end_of_list:
    pop rbx
    mov rax, rcx
    mov rsp, rbp
    pop rbp
    ret

nullpointer:
    xor rax, rax
    jmp end_of_list