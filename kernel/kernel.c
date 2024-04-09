#include "../include/common.h"
#include "../include/vga.h"
#include "../include/description_table.h"
#include "../include/io.h"
#include "../include/memory.h"
#include "../include/timer.h"
#include "../include/task.h"
#include "../include/cmos.h"
#include "../include/keyboard.h"
#include "../include/shell.h"

extern uint32_t end;
uint32_t placement_address = (uint32_t) & end;


void kernel_main() {
    io_cli();
    vga_install();
    printf("[kernel]: VGA driver load success!\n");
    gdt_install();
    idt_install();
    printf("[kernel]: description table config success!\n");
    init_timer(10);
    init_page();
    printf("[kernel]: page set success!\n");
    init_sched();
    printf("[kernel]: PCB load success!\n");
    init_keyboard();
    printf("[kernel]: Keyboard driver load success!\n");
    print_cpu_id();
    io_sti();

    clock_sleep(25);

    kernel_thread(setup_shell,NULL,"CPOS-Shell");


    for (;;){
        io_hlt();
        clock_sleep(1);
    }
}