/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2025 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#include <memory.h>
#include <panic.h>
#include <asm/idt.h>
#include <pci.h>

// extern because everything is still linked :(
extern int terminal_main(uint16_t theme);

void main() {
    init_memory();
    idt_install();
    terminal_main(0x0B);
}