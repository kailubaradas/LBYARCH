;DRAFT, not working ATM

section .data

section .text
bits 64
default rel 
global dot_product_asm
extern printf

dot_product_asm:
    xorps xmm0, xmm0       
    xor rcx, rcx           

dot_product_loop:
    cmp rcx, rdx           
    jge dot_product_done   

    movss xmm1, dword [rdi + rcx * 4] 
    movss xmm2, dword [rsi + rcx * 4] 

    mulss xmm1, xmm2
    addss xmm0, xmm1

    inc rcx
    jmp dot_product_loop

dot_product_done:
    ret
