section .data
    struc node
        info resq 1
        next resq 1
    endstruc

section .text
    global ft_list_size     ; ft_list_size(t_list *begin_list);

ft_list_size:
    xor rcx, rcx            ; Set rcx to 0 (Counter)

    push rbp                ; Save the old base pointer
    mov rbp, rsp            ; Setup a new base pointer

    push rbx                ; Save rbx to use it for traversing the list
    mov rbx, rdi            ; Move the 1st argument (our list)

    test rbx, rbx           ; Check if the list is empty
    je nullpointer          ; Jump if the list is NULL

next_element:
    inc rcx                 ; Increment rcx
    mov rdx, [rdx + next]   ; Mov to the next node
    test rdx, rdx           ; Check if the next node is empty
    jne next_element        ; Loop until the next node is not empty

end_of_list:
    pop rbx                 ; Retrieve head of list from stack

    mov rax, rcx            ; Move rcx to rax (rax = Counter)
    mov rsp, rbp            ; Move base pointer to stack pointer

    pop rbp                 ; Retrieve base pointer from stack
    ret                     ; Return index

nullpointer:
    xor rax, rax            ; rax = 0 if the list is empty
    jmp end_of_list         ;
