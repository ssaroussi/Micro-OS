global loader

MAGIC_NUMBER equ 0x1BADB002
FLAGS        equ 0x0            
CHECKSUM     equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 4096

section .text                  
	align 4                         
	dd MAGIC_NUMBER            
	dd FLAGS                    
	dd CHECKSUM            


	loader:
		mov esp, kernel_stack + KERNEL_STACK_SIZE

		extern kmain
		call kmain

	.loop:
		jmp .loop

	
	extern pGDT
	global gdt_flush

	gdt_flush:
		lgdt[pGDT]  ; load the gdt
		mov ax, 0x10 ; move ax into the data segment in the gdt
		mov ds, ax   ; clean the registers
		mov ss, ax
		mov ds, ax
		mov es, ax
		mov fs, ax
		mov gs, ax
		jmp 0x08:flush
	flush:
		ret

	extern pIDT
	global load_idt
        
	load_idt:
		lidt[pIDT]
		ret

section .bss
align 4
	kernel_stack:
		resb KERNEL_STACK_SIZE      

