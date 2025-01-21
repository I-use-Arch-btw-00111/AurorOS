/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2024 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#pragma once

#define COLOR_1 0x47
#define COLOR_2 0x4F
#define COLOR_3 0x44

#include <msg.h>
#include <types.h>
#include <screen.h>
#include <constants.h>

void kernelpanic(const char *errcode) {
    paintscreen(COLOR_3);
    println(" ", COLOR_1);
    println(" Kernel panic!", COLOR_2);
    println(" ", COLOR_1);
    print(" The system encountered a problem and could not continue! \n You can turn off the computer manually using the power button.", COLOR_1);
    println(" ", COLOR_1);
    print(" Error code: ", COLOR_1);
    print(errcode, COLOR_2);
    println(" ", COLOR_1);
    println(" ", COLOR_1);
    
    println("Additional info:", COLOR_2);
        
    if (AUROR_CODE_PHASE == EARLY_BUILD) {
        println("AurorOS release type: Early Build", COLOR_1);
    } else if (AUROR_CODE_PHASE == PUBLIC_BETA) {
        println("AurorOS release type: Public Beta Build", COLOR_1);
    } else if (AUROR_CODE_PHASE == STABLE_BUILD) {
        println("AurorOS release type: Stable Build", COLOR_1);
    }

    print(" AurorOS version: ", COLOR_1);
    print(AUROR_VERSION, COLOR_2);
    
    while (true) {
        asm("hlt");
    }
}
