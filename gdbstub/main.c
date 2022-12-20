#include "i386-stub.h"
#include "crc.h"
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>

void setupGDB() {
  gdb_serial_init(1);
  gdb_target_init();
  breakpoint();
}

int main(int argc, char **argv) {
    setupGDB();

    int a = 0;
    int b = 2;
    int c = a + b;
    printf("WTF\n");
    return 0;
}