#include "stdio.h"
#include "stdlib.h"
#include "../include/cpos.h"

void print_info(){

    struct sysinfo *info = get_sysinfo();

    printf("               .:=*#&&@@@@@@&&#+=:.               \n"
           "            -+&@@@@@@@@@@@@@@@@@@@- ----------.          -----------------\n"
           "         -*@@@@@@@@@@@@@@@@@@@@&=.-&@@@@@@@@@@+          OSName:     %s\n"
           "       =&@@@@@@@@@@@@@@@@@@@@@=.-&@@@@@@@@@@@@+          Kernel:     %s\n"
           "     -&@@@@@@@@@@@@@@@@@@@@@=.-&@@@@@@@@@@@@@@+          CPU Vendor: %s\n"
           "    *@@@@@@@@@@@@@@@@@@@@@=.-&@@@@@@@@@@@@@@@@+          CPU:        %s\n"
           "  .&@@@@@@@@@@@@@@@&*=-:: :#@@@@@@@@@@@@@@@@@@=          Memory:     %dMB\n"
           "  &@@@@@@@@@@@@@&=.       #@@@@@@@@@@@@@@@@@#:.=         Console:    CPOS_USER_SHELL\n"
           " *@@@@@@@@@@@@@-          #@@@@@@@@@@@@@@@#:.=@@+        PCI Device: %d\n"
           ":@@@@@@@@@@@@&.           #@@@@@@@@@@@@@#: =@@@@@.       Resolution: %d x %d\n"
           "#@@@@@@@@@@@@.            #@@@@@@@@@@@#: =@@@@@@@+       Time:       %d/%d/%d %d:%d\n"
           "@@@@@@@@@@@@+             *&&&&&&&&&#- =@@@@@@@@@&\n"
           "@@@@@@@@@@@@-                        :@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@+                        #@@@@@@@@@@@&\n"
           "*@@@@@@@@@@@@.                      :@@@@@@@@@@@@+\n"
           ":@@@@@@@@@@@@&.                    :@@@@@@@@@@@@@.\n"
           " *@@@@@@@@@@@@@=                  =@@@@@@@@@@@@@+ \n"
           "  #@@@@@@@@@@@@@&+:            :+@@@@@@@@@@@@@@#  \n"
           "   #@@@@@@@@@@@@@@@&*+=----=+#&@@@@@@@@@@@@@@@*   \n"
           "    +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+    \n"
           "     :&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:     \n"
           "       -#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-       \n"
           "         :*@@@@@@@@@@@@@@@@@@@@@@@@@@@&+:         \n"
           "            :+#@@@@@@@@@@@@@@@@@@@@#+:            \n"
           "                :=+*#&@@@@@@&#*+-:                \n",
           info->osname,
           info->kenlname,
           info->cpu_vendor,
           info->cpu_name,
           info->phy_mem_size,
           info->pci_device,
           info->frame_width,
           info->frame_height,
           info->year,
           info->mon,
           info->day,
           info->hour,
           info->min,
           info->sec);

    free_info(info);
}