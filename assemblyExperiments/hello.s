section .data
    message db "Hello, World!", 0xA  ; The message to print with a newline
    msg_len equ $ - message          ; Calculate the length of the message

section .text
    global _start
    
_start:
    ; Write system call (sys_write)
    mov rax, 1          ; System call number for sys_write (1)
    mov rdi, 1          ; File descriptor (1 = stdout)
    mov rsi, message    ; Pointer to the message
    mov rdx, msg_len    ; Length of the message
    syscall             ; Make the system call

    ; Exit system call (sys_exit)
    mov rax, 60         ; System call number for sys_exit (60)
    xor rdi, rdi        ; Exit code (0)
    syscall             ; Make the system call
