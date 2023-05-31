print_hex:
    pusha
    mov cx, 0 ; index

print_hex_loop:
    cmp cx, 4
    je print_hex_done

    mov ax, dx
    and ax, 0x00f
    add al, 0x30
    cmp al, 0x39
    jle print_hex_step2
    add al, 7

print_hex_step2:
    mov bx, OUT + 5
    sub bx, cx
    mov [bx], al
    ror dx, 4

    inc cx
    jmp print_hex_loop

print_hex_done:
    mov bx, OUT
    call print

    popa
    ret

OUT:
    db "0x0000", 0