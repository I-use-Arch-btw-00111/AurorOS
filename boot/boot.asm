; -------------------------------------------------------------------------
;                                   AurorOS
; (c) 2022-2024 Interpuce
; 
; You should receive AurorOS license with this source code. If not - check:
;  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
; -------------------------------------------------------------------------

; boot.asm configures everything (including Multiboot Header required by GRUB
; and other bootloaders to see AurorOS) and loads the kernel main function
; from /kernel/kernel.c

; If you are editing this file on a Visual Studio Code, please download
; extension for x86 assembly syntax.

bits 32

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

section .text
global start
extern main

start:
    cli
    call main
    hlt 
