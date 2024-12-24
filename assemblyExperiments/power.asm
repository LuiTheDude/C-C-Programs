global _start

section .text
_start:
    mov rbx, 1  ;start rbx at 1
    mov rcx, 5  ;number of iterations
label:
    add rbx, rbx    ;rbx += rbx
    dec rcx         ;rcx--
    cmp rcx, 0      ;compare rcx to 0
    jg label        ;jump to label if greater
    mov rax, 60     ;syscall number for sys_exit
    mov rdi, rbx      ;exit code 0
    syscall


; 0x0000000000001129 <+0>:     endbr64 
; 0x000000000000112d <+4>:     push   rbp
; 0x000000000000112e <+5>:     mov    rbp,rsp
; 0x0000000000001131 <+8>:     mov    DWORD PTR [rbp-0x8],0x1
; 0x0000000000001138 <+15>:    mov    DWORD PTR [rbp-0x4],0x5
; 0x000000000000113f <+22>:    jmp    0x1148 <main+31>
; 0x0000000000001141 <+24>:    shl    DWORD PTR [rbp-0x8],1
; 0x0000000000001144 <+27>:    sub    DWORD PTR [rbp-0x4],0x1
; 0x0000000000001148 <+31>:    cmp    DWORD PTR [rbp-0x4],0x0
; 0x000000000000114c <+35>:    jg     0x1141 <main+24>
; 0x000000000000114e <+37>:    mov    eax,DWORD PTR [rbp-0x8]
; 0x0000000000001151 <+40>:    pop    rbp
; 0x0000000000001152 <+41>:    ret 