/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2025 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#include <types.h>
#include <constants.h>
#include <string.h>

int translate_permission_level(string user) {
    if (streql(user, "main") == 0) {
        return PERMISSION_LEVEL_MAIN; // already a main user
    } else {
        return PERMISSION_LEVEL_MUSEABLER; // can execute muse (main user shell execute)
    }
}