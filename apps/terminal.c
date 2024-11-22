/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2024 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#include <types.h>
#include <console.h>
#include <string.h>
#include <constants.h>
#include <declarations/time.h>
#include <declarations/math.h>
#include <rtc.h>

extern int run_appman(const string user);

void run_terminal(const string user) {
    while (1)
    {
        print("\n", 0x07);
        print(user, 0x05);
        print("@AurorOS > ", 0x05);
  
        string ch = read(0x07);
        
        if (string_equal(ch, "ver") || string_equal(ch, "version")) {
            if (AUROR_BETA_STATE == 0) {
                print("AurorOS ", 0x07);
                println(AUROR_VERSION, 0x07);
            }
            if (AUROR_BETA_STATE == 1) {
                print("AurorOS ", 0x07);
                print(AUROR_VERSION, 0x07);
                print(" (beta ", 0x07);
                print(AUROR_SUBVERSION, 0x07);
                println(")", 0x07);
                println("This version is very unstable and may contain errors and bugs. Let us know on dsc.gg/Auror-OS", 0x04);
            }
            if (AUROR_BETA_STATE == 2) {
                print("AurorOS ", 0x07);
                print(AUROR_VERSION, 0x07);
                print(" (alpha ", 0x07);
                print(AUROR_SUBVERSION, 0x07);
                println(")", 0x07);
                println("This version is very unstable and may contain errors and bugs. Let us know on dsc.gg/Auror-OS", 0x04);
            }
        } else if (string_equal(ch, "time")) {
            time_t current_time;
            get_current_time(&current_time);
            string hours;
            int_to_text(current_time.hours, hours);
            print(hours, 0x07);
            print(":", 0x07);
            string minutes;
            int_to_text(current_time.minutes, minutes);
            print(minutes, 0x07);
            print(":", 0x07);
            string seconds;
            int_to_text(current_time.seconds, seconds);
            println(seconds, 0x07);
        } else if (string_equal(ch, "clear")) {
            clear_console();
        } else if (string_equal(ch, "mush")) {
            if (string_equal(user, "main")) {
                println("mush: cannot request main user access when user already has it", 0x04);
                continue;
            }
            println("mush: attempting to start terminal as main user", 0x02);
            println("mush: main user password required; default is xxx", 0x07);
            if (string_equal(invisible_read_string(0x07), "xxx")) {
                run_terminal("main");
                println("mush: terminal process exited; returning to main instance", 0x07);
            } 
        } else if (string_equal(ch, "quit") || string_equal(ch, "exit")) {
            break;
        } else if (string_equal(ch, "appman")) {
            run_appman(user);
        } else if (string_equal(ch, "colormap")) {
            print("\nAurorOS ", 0x07); print("AurorOS ", 0x70);
            print("\nAurorOS ", 0x06); print("AurorOS ", 0x60);
            print("\nAurorOS ", 0x05); print("AurorOS ", 0x50);
            print("\nAurorOS ", 0x04); print("AurorOS ", 0x40);
            print("\nAurorOS ", 0x03); print("AurorOS ", 0x30);
            print("\nAurorOS ", 0x02); print("AurorOS ", 0x20);
            print("\nAurorOS ", 0x01); print("AurorOS ", 0x10);
            print("\nAurorOS ", 0x0F); print("AurorOS ", 0xF0);
            print("\nAurorOS ", 0x0E); print("AurorOS ", 0xE0);
            print("\nAurorOS ", 0x0D); print("AurorOS ", 0xD0);
            print("\nAurorOS ", 0x0C); print("AurorOS ", 0xC0);
            print("\nAurorOS ", 0x0B); print("AurorOS ", 0xB0);
            print("\nAurorOS ", 0x0A); print("AurorOS ", 0xA0);
        } else {
            print("Invalid command!\n", 0x04);
        }
    }
}