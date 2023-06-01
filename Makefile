all: bootloader kernel run

bootloader:
	nasm BootLoader/BootLoader.asm -f bin -o BootLoader.bin

kernel:
	i386-elf-gcc -ffreestanding -c Kernel/Kernel.c -o Objs/Kernel.o
	nasm Kernel/KernelEntry.asm -f elf -o Objs/KernelEntry.o
	i386-elf-ld -o Kernel.bin -Ttext 0x1000 Objs/KernelEntry.o Objs/Kernel.o --oformat binary
	cat BootLoader.bin Kernel.bin > CopperOS.bin
	rm BootLoader.bin
	rm Kernel.bin

run:
	qemu-system-x86_64 -fda CopperOS.bin

clean:
	rm CopperOS.bin
	rm Objs/*