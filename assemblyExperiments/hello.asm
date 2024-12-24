section .data
    msg db "hello world", 0x0a ; creates string variable msg and ends it with '/n'
    len equ $ - msg           ; gets length of msg

section .text
global _start
_start:
    mov rax, 4      ; sys_write syscall
    mov rbx, 1      ; stdout file descriptor
    mov rcx, msg    ; address of message
    mov rdx, len    ; number of bytes to write
    int 0x80        ; syscall

    mov rax, 1      ; sys_exit syscall
    mov rbx, 0      ; exit code 0
    syscall         ; syscall