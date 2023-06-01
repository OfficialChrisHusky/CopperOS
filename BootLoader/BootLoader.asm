[org 0x7c00]
KERNEL_OFFSET equ 0x1000

    mov [BOOT_DRIVE], dl
    mov bp, 0x9000
    mov sp, bp

    mov bx, MSG_REAL_MODE
    call print
    call print_nl

    call load_kernel
    call switch_to_pm
    jmp $ ; This should definitely never be reached

%include "BootLoader/Print.asm"
%include "BootLoader/PrintHex.asm"
%include "BootLoader/DiskLoad.asm"
%include "BootLoader/GDT.asm"
%include "BootLoader/32BitPrint.asm"
%include "BootLoader/32BitSwitch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET ; Enter the Kernel

    mov ebx, MSG_KERNEL_RETURNED
    call print_string_pm
    jmp $ ; Hand here, even though we should never get to this line

BOOT_DRIVE db 0

MSG_REAL_MODE db "Started in 16-bit real mode", 0
MSG_PROT_MODE db "Loaded 32-bit protected mode", 0
MSG_LOAD_KERNEL db "Loading Kernel into memory", 0

MSG_KERNEL_RETURNED db "Kernel Returned Control to the Bootloader, This should never Happen!", 0

times 510-($-$$) db 0
dw 0xaa55