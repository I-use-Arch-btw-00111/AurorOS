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

#include <types.h>

void print_error(const string str);
void print_info(const string str);
void print_ok(const string str);
void print_warn(const string str);
void print_custom(const string str, uint8_t color, uint8_t scolor);
void print(const string str, uint8_t color);
void println(const string str, uint8_t color);
