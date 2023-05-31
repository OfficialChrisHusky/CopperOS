print:
    pusha
    mov ah, 0x0e

print_loop:
    mov al, [bx]
    cmp al, 0
    je print_done

    int 0x10
    inc bx
    jmp print_loop

print_done:
    popa
    ret

print_nl:
    pusha
    mov ah, 0x0e

    mov al, 0x0a
    int 0x10
    mov al, 0x0d
    int 0x10

    popa
    ret