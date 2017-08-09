%macro ISR_ERRCODE 1
	[GLOBAL isr%1]
	isr%1:
		cli
		push byte %1 ;; interrupt number

		jmp isr_common
%endmacro


ISR_ERRCODE    8	;; Double Fault Exception
ISR_ERRCODE   10	;; Bad TSS Exception
ISR_ERRCODE   11	;; Segment Not Present Exception
ISR_ERRCODE   12	;; Stack Fault Exception
ISR_ERRCODE   13	;; General Protection Fault Exception
ISR_ERRCODE   14	;; Page Fault Exception

%macro ISR_NOERRCODE 1
	[GLOBAL isr%1]
	isr%1:
		cli
		push byte  0 ;; dummy error code
		push byte %1 ;; interrupt number

		jmp isr_common
%endmacro

ISR_NOERRCODE  0 	;; Division By Zero Exception
ISR_NOERRCODE  1	;; Debug Exception
ISR_NOERRCODE  2    ;; Non Maskable Interrupt Exception
ISR_NOERRCODE  3	;; Breakpoint Exception
ISR_NOERRCODE  4	;; Into Detected Overflow Exception
ISR_NOERRCODE  5	;; Out of Bounds Exception
ISR_NOERRCODE  6	;; Invalid Opcode Exception
ISR_NOERRCODE  7	;; No Coprocessor Exception
ISR_NOERRCODE  9	;; Coprocessor Segment Overrun Exception
ISR_NOERRCODE 15	;; Unknown Interrupt Exception
ISR_NOERRCODE 16	;; Coprocessor Fault Exception
ISR_NOERRCODE 17	;; Alignment Check Exception (486+)
ISR_NOERRCODE 18	;; Machine Check Exception (Pentium/586+)

;; Reserved Exceptions
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31

isr_common:
	; Save and wipe current state of pretty much everything
	pusha
	push ds
	push es
	push fs
	push gs

	mov ax, 0x10 ;load the data seg descriptor

	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax

	[EXTERN isr_handler]
	mov eax, isr_handler
	call eax

	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa

	add esp, 8 ; clean the error code and irs number
	iret

%macro IRQ 2
	[GLOBAL irq%1]
	irq%1:
		cli
		push byte 0  ;; dummy err code
		push byte %2 ;; irq number

		jmp irq_common
%endmacro

IRQ  0,	32
IRQ  1,	33
IRQ  2,	34
IRQ  3,	35
IRQ  4,	36
IRQ  5,	37
IRQ  6,	38
IRQ  7,	39
IRQ  8,	40
IRQ  9,	41
IRQ 10,	42
IRQ 11,	43
IRQ 12,	44
IRQ 13,	45
IRQ 14,	46
IRQ 15,	47

irq_common:
	; Save and wipe current state of pretty much everything
	pusha
	push ds
	push es
	push fs
	push gs

	mov ax, 0x10 ;load the data seg descriptor

	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax

	[EXTERN irq_handler]
	mov eax, irq_handler
	call eax

	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa

	add esp, 8 ; clean the error code and irs number
	iret
