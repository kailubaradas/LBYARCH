section .data
    
section .text
bits 64
global dotProduct

dotProductAsm:
    xorps xmm0, xmm0       ; Clear xmm0 to store the sum (result)
    xor rcx, rcx          

dot_product_loop:
    cmp rcx, rdx           
    jge dot_product_done   

    ; Load arrayX[rcx] and arrayY[rcx] into xmm1 and xmm2
    movss xmm1, dword [rdi + rcx * 4]  
    movss xmm2, dword [rsi + rcx * 4]  

    mulss xmm1, xmm2      
    addss xmm0, xmm1       

    inc rcx                
    jmp dot_product_loop   ; Repeat loop

dot_product_done:
    ret                    
