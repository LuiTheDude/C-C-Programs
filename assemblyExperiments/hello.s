section .data
    message db "Hello, World!", 0  ; Null-terminated string

section .text
    global _start                  ; Entry point for Linux

_start:
    mov rax, 1                    ; syscall: write
    mov rdi, 1                    ; file descriptor: stdout
    lea rsi, [message]            ; address of string
    mov rdx, 13                   ; length of string
    syscall                       ; invoke the system call

    mov rax, 60                   ; syscall: exit
    xor rdi, rdi                  ; exit code 0
    syscall
