global loader					; symbol for elf

; GRUB multiboot specification
MAGIC_NUMBER equ 0x1BADB002		; magic number for grub
FLAGS		 equ 0x0			; multiboot flags
CHECKSUM 	 equ -MAGIC_NUMBER	; calculate check sum

KERNEL_STACK_SIZE equ 0x1000
extern kmain

section .text:
align 4		
	dd MAGIC_NUMBER				; write the magic number to the code
	dd FLAGS					; ^
	dd CHECKSUM					; ^

loader:							; entry point at link
	mov esp, kernel_stack + KERNEL_STACK_SIZE

	call kmain

.loop:
	jmp .loop

section .bss
align 4
kernel_stack:
	resb KERNEL_STACK_SIZE
