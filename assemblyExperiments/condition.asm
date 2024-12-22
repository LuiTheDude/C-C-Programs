global _start

section .text
_start:
    mov ecx, 101
    mov eax, 1  ;sys_exit
    mov ebx, 42 ;exit status
    cmp ecx, 100 ;compare ecx value to 100
    jl skip    ;jump to skip if less than
    mov ebx, 13 
skip:
    int 0x80   ;syscall