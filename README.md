# LIBASM
## 📝 Introduction
During this piscine, I learned the basic knowledge to know about **assembly** language or as it often call **asm**. 

I will explain everything I learned about it !

## ⚙️ Compiling
To compile this library, ensure that both the `nasm` and `gcc` compilers installed on your system.

This library can only be compiled on a Linux system.

After cloning this repository, run `make` in the root directory to generate the object files and the `libasm.a` library.

There are two parts, `mandatory` and `bonus`.

To test `ft_list_size`, run `make bonus`. This will create an executable named `./test`.

To test the remaining functions, run `make mandatory`.

## 📜 Basic Syntax
An **assembly** program can be divided into `3 sections`.
### **data** section
The **data** section is used for declaring initialized data or constants. This **data** *does not change at runtime*.

**Declaring data section**
```asm
section .data
```

### **bss** section
The **bss** section is used for declaring variables.

**Declaring bss section**

```asm
section .bss
```

### **text** section
The **text** section is used for keeping the actual code. This section must begin with the declaration **global _start**, which tells the kernel where the program execution begins.

**Declaring text section**

```asm
section .text
```

## 💾 Registers
Now, let's talk about registers !

**Assembly** works maily with registers. They can be compared to litte pre-defined boxes that can store data.

The general purpose registers are :

 * **RAX** is used to stored the return value of a function  
 * **RCX** is used as a counter in loops
 * **RSP** is used to store the stack pointer
 * **RBP** is used to store the base pointer
 * **RDI** corresponds to the 1st argument of a function
 * **RSI** corresponds to the 2nd argument of a function
 * **RDX** corresponds to the 3rd argument of a function
 * **R8** corresponds to the 5th argument of a function
 * **R9** corresponds to the 6th argument of a function

## 🐧 Linux System Calls
We can make use of **Linux system calls** in your assembly programs.

You need to take the following steps for using **Linux system calls** in your program.

The following code snippet the usage of the system call *sys_write* :

```asm
mov	rdx, 4		; message length
mov	rcx, msg	; message to write
mov	rbx, 1		; file descriptor (stdout)
mov	rax, 1		; system call number (sys_write)
syscall         ; invoke the system call
ret             ; return the result
```

The following code snippet shows the usage of the system call 
*sys_exit* :

```asm
mov rax, 0      ;system call number (sys_exit)
syscall         ; invoke the system call
ret             ; return the result
```

All the syscalls are listed in `/usr/include/asm/unistd.h` together with their numbers (the value to put in **RAX** before you call **syscall**).

The following table shows some of the system calls :

|**%rax**|**Name**|**%rbx**|**%rcx**|**%rdx**|**%rsx**|**%rdi**|
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
|   1    | sys_exit | int | - | - | - | - |
|   2    | sys_fork | struct pt_regs | - | - | - | - |
|   3    | sys_read | unsigned int | char* | size_t | - | - |
|   4    | sys_write | unsigned int | const char* | size_t | - | - |
|   5    | sys_open | const char* | int | int | - | - |
|   6    | sys_close | unsigned int | - | - | - | - |

## ✏️ Syntax
The syntax used here is the ***Intel*** syntax. It is the most common syntax used in assembly programming, and a requisite of the subject. It is characterized by the fact that that the destination operand is on the **left** and the source operand is on the **right**. 

### 🛠️📜 Instructions
Virtually **all the lines in assembly** are composed of an **instruction followed by its operand(s)**.

A few examples :
- `mov rax, 0` copies the value `0` into the register `rax`.
- `add rax, 1` adds the value `1` into the register `rax`.
- `cmp rax, 0` compares the value in the register `rax` with `0`.
- `jmp loop` jumps to the label `loop`.

## 📍🔢 Addresses and values
Like in **C**, we can work with addresses.

The square brackets `[]` are used to dereference an address.

For example, if we want to move the value at the address `0x1234` into the register `rax`, we can do :

```asm
mov rax, [0x1234]
```

if we want to compare the address 3 bytes after the address in `rax` with `0`, we can do :

```asm
cmp [rax + 3], 0
```

We should technically use an identifier for the address (`BYTE`, `WORD`, `DWORD`, `QWORD`) to specify the size of the data we want to compare.

This table shows some of the common type specifiers :

| **Type Specifier** | **Bytes addressed** |
| ------------------ | ------------------- |
| `BYTE` | 1 |
| `WORD` | 2 |
| `DWORD` | 4 |
| `QWORD` | 8 |
| `TBYTE` | 10 |

## 📦 Exporting symbols
In order to use the functions we write in assembly in a C program, we need to export them.

To do so, we can use the `global` directive.

For example, if we want to export the function `ft_write`, we can do :
```asm 
global ft_write
```
```asm
ft_write:
    ...
```

## ft_strlen
The `ft_strlen` function is a function that returns the length of a string.

It is a very simple function that iterates over the string until it finds the null-terminator (`\0`).

```asm 
global ft_strlen			; ft_strlen(const char *str)

ft_strlen:
	xor rcx, rcx			; Initialize rcx to 0, this will be our counter

.loop:
	mov al, byte [rdi + rcx]	; Load the byte at address [rdi + rcx] into al
	test al, al			; Perform a bitwise AND operation of `al` with itself to set the ZF flag
	je .end				; If al is zero (end of string), jump to .end
	inc rcx				; Increment rcx
	jmp .loop			; Repeat the loop

.end:
	mov rax, rcx			; Move the count (rcx) to rax (return value)
	ret				; Return the result
```

## ft_strcpy
The `ft_strcpy` function is a function that copies a string from a source to a destination and returns the destination.

```asm
global ft_strcpy                ; ft_strcpy(char *dest, const char *src)

ft_strcpy:
    xor rcx, rcx                ; Initialize rcx to 0, this will be our counter

.loop:
    mov rdx, [rsi + rcx]        ; move the byte from [rsi + rcx] to rdx - rsi is our 2nd parameter (src)
    mov [rdi + rcx], rdx        ; move rdx to [rdi + rcx] - rdi is our 1st parameter (dest)
    test rdx, rdx               ; AND operator if rdx is equal to 0 and set FLAG_ZERO (FZ) - null terminator
    je .end                     ; Jump to .end if rdx is equal to 0
    inc rcx                     ; Increment rcx to move to the next byte
    jmp .loop                   ; Return the loop

.end:
    mov rax, rdi                ; Move the destination pointer [rdi] to rax as the return value
    ret                         ; return from the function
```

## ft_strcmp
The `ft_strcmp` functions compares two strings lexicographically and returns an integer indicating the result of the comparison.

```asm
global ft_strcmp                    ; int ft_strcmp(const char *s1, const char *s2)

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

```

## ft_strdup
The `ft_strdup` function is used to duplicate a string from a source, it allocates memory for a new string and copies the source string into this newly allocated space.

```asm
global ft_strdup		; char *ft_strdup(const char *s)
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	call ft_strlen 		; Call ft_strlen, that saves the length in rax
	push rdi		; Push rdi (that contain *s)
	inc rax			; Increment by 1 (for the null-terminator)
	mov rdi, rax		; move the length (rax) to rdi
	call malloc		; call malloc
	test rax, rax		; verify if calloc return  -1
	jz err			; err if -1
	pop rsi			; Pop *s from the stack to rsi (2nd arguments of ft_strcpy)
	mov rdi, rax    	; move the allocated memory to rdi (1st argument of ft_strcpy)
	call ft_strcpy		; call strcpy, copy rdi to rax
	ret			; return rax

err:
	mov rax, -1		; set rax to -1 if malloc return -1
    ret				; return sys_call
```

## ft_write
The `ft_write` function is used to write data. 

It takes 3 arguments : `fd` (file descriptor), `buffer` (the data to write) and `buffer_size` (the length of bytes to write).

```asm
extern __errno_location
global ft_write                 ; ssize_t write(int fd, const void buf, size_t count)

ft_write:
    mov rax, 1                  ; Syscall number for sys_write
    syscall                     ; Perform the syscall

    test rax, rax               ; Test if the return value (rax) is negative
    je err                      ; Jump to error handling if flag sign is set (negative value)
    ret                         ; Return is no error

err:
    neg rax                     ; Convert the regative value to a positive error code
    mov rdi, [rax]              ; Move the error code to rdi register (for errno_location call)
    call __errno_location       ; Call errno_location
    mov rax, [rdi]              ; Get the reference of rdi to store the error code in rax register
    mov rax, -1                 ; Retunr -1 for indicate an error
    ret                         ; Return the error code
```

## ft_read
The `ft_read` function is used to read a file.
It takes 3 arguments : `fd` (file descriptor), `buffer` (the data to read) and `buffer_size` (the size of the data to read).

```asm
extern __errno_location
global ft_read

ft_read:                    ; ssize_t   ft_read(int fd, void *buf, size_t count);
    mov rax, 0              ; Set rax with sys_read parameters
    syscall

    test rax, rax           ; Check if rax return 0
    jl  err                 ; If -1 return an error
    ret                     ; Return rax

err:
    neg rax
    mov rdi, [rax]
    call __errno_location
    mov rax, [rdi]
    mov rax, -1
    ret
```

## ft_list_size
The `ft_list_size` function, like `ft_strlen` for strings, is used to get the length of a linked list.

```asm 
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
```

## Resources

- [libasm a guide to get familiar with assembly](https://medium.com/@leogaudin/libasm-a-guide-to-get-familiar-with-assembly)
- [Assembly programming](https://www.tutorialspoint.com/assembly_programming)
- [X86 Assembly](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture#Instruction_Pointer)
