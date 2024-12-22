global _start
_start:
    mov rax, 1  ;sys_exit syscall
    mov ebx, 42 ;exit status
    sub ebx, 10 ;subtraction
    int 0x80    ;executes syscall in ebx register