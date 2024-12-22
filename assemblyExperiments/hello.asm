section .data
    msg db "hello world", 0x0a ; creates string variable msg and ends it with '/n'
    len equ $ - msg           ; gets length of msg

section .text
global _start
_start:
    mov eax, 4      ; sys_write syscall
    mov ebx, 1      ; stdout file descriptor
    mov ecx, msg    ; address of message
    mov edx, len    ; number of bytes to write
    int 0x80        ; syscall

    mov eax, 1      ; sys_exit syscall
    mov ebx, 0    ; exit code 0
    int 0x80        ; syscall