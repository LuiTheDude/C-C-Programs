global _start

section .text
_start:
    mov eax, 1  ;sys_exit
    mov ebx, 42 ;exit status
    jmp skip    ;jump to skip
    mov ebx, 13 
skip:
    int 0x80   ;syscallS