SRCS = $(wildcard Kernel/*.c Kernel/*/*.c)
HDRS = $(wildcard Kernel/*.h Kernel/*/*.h)

OBJDIR := Objs
OBJS_TMP = $(SRCS:.c=.o)
OBJS = $(foreach wrd, $(OBJS_TMP), $(OBJDIR)/$(wrd))
OBJS += Objs/Kernel/KernelEntry.o Objs/Kernel/Interrupts/Interrupts.o

BOOTLOADER_SRCS = $(wildcard BootLoader/*.asm)

ASM = nasm
CC = i386-elf-gcc
LD = i386-elf-ld

CFLAGS = -ffreestanding -IKernel
LDFLAGS = -Ttext 0x1000 --oformat binary
ASMFLAGS = -f elf

all: bootloader kernel image run

kernel: $(OBJS) Kernel.bin
bootloader: BootLoader.bin
image: CopperOS.bin
run: CopperOS.bin
	@qemu-system-x86_64 -fda CopperOS.bin

$(OBJDIR)/Kernel/%.o: Kernel/%.c $(HDRS)
	@mkdir -p "$(@D)"
	@echo Compiling Kernel/$<
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/Kernel/%.o: Kernel/%.asm
	@echo Compiling Kernel/$<
	@$(ASM) $< $(ASMFLAGS) -o $@

Kernel.bin: $(OBJS)
	@echo ========Linking Kernel========
	@$(LD) -o $@ $(LDFLAGS) $^
BootLoader.bin: $(BOOTLOADER_SRCS)
	@echo ========Linking Boot Loader========
	@$(ASM) BootLoader/BootLoader.asm -f bin -o BootLoader.bin
CopperOS.bin: Kernel.bin BootLoader.bin
	@echo ========Merging the Boot Loader and the Kernel========
	@cat BootLoader.bin Kernel.bin > CopperOS.bin

clean:
	@echo Removing the Binaries
	@rm CopperOS.bin
	@rm BootLoader.bin
	@rm Kernel.bin
	@echo Removing the Object Files
	@rm -r Objs