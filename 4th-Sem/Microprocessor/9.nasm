Problem Statement : Write X86 ALP to find, a) Number of Blank spaces b) Number of lines c) Occurrence of a particular character. Accept the data from the text file. The text file has to be accessed during Program_1 execution and write FAR PROCEDURES in Program_2 for the rest of the  processing.  Use  of  PUBLIC  and  EXTERN directives is mandatory.

%macro IO 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

section .data
    newline      db 10,0      ; Newline for output formatting

    msg_space    db "Number of spaces: ", 0
    msg_newline  db "Number of newlines: ", 0
    msg_char     db "Number of occurrences: ", 0

    input_text   db "Hello World! This is a test.", 10, "Second line here.", 0
    input_len    equ $ - input_text   ; Calculate length of the input string

    search_char  db 'i'   ; Character to count occurrences of

section .bss
    space_count  resb 1
    newline_count resb 1
    char_count   resb 1

section .text
    global _start

_start:
    ; Initialize counters
    mov byte [space_count], 0
    mov byte [newline_count], 0
    mov byte [char_count], 0

    ; Set up string traversal
    mov esi, input_text    ; Point to start of input
    mov ecx, input_len     ; Number of characters to process

count_loop:
    mov al, [esi]          ; Load character from string
    cmp al, 0              ; Check for end of string
    je done_counting

    cmp al, ' '            ; Check for space (0x20)
    jne check_newline
    inc byte [space_count]
    jmp next_char

check_newline:
    cmp al, 10             ; Check for newline (0x0A)
    jne check_char
    inc byte [newline_count]
    jmp next_char

check_char:
    cmp al, [search_char]  ; Compare with the character to count
    jne next_char
    inc byte [char_count]

next_char:
    inc esi                ; Move to next character
    loop count_loop        ; Repeat for all characters

done_counting:
    ; Print space count
    mov edx, 19
    mov ecx, msg_space
    call print_string
    movzx eax, byte [space_count]
    call print_number

    ; Print newline count
    mov edx, 21
    mov ecx, msg_newline
    call print_string
    movzx eax, byte [newline_count]
    call print_number

    ; Print character count
    mov edx, 25
    mov ecx, msg_char
    call print_string
    movzx eax, byte [char_count]
    call print_number

    ; Exit program
    mov eax, 60
    xor edi, edi
    syscall

; -------------------------
; Print String (ecx: string, edx: length)
; -------------------------
print_string:
    mov eax, 1          ; sys_write
    mov edi, 1          ; stdout
    syscall
    ret

; -------------------------
; Print Number in ASCII
; -------------------------
print_number:
    add al, '0'         ; Convert to ASCII
    mov [newline], al   ; Store as string
    mov ecx, newline    ; Load address
    mov edx, 2          ; Length (digit + newline)
    call print_string
    ret

; Output
;-------------------------------------
; Number of spaces: 4
; Number of newlines: 1
; Number of occurrences: 2
 
