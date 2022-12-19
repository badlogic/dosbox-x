#include "i386-stub.h"
#include "crc.h"
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>

#define COM_PORT 0

void testCOM() {
  char *buf = "Hello world";
  printf("Waiting: %i\n", _bios_serialcom(_COM_RECEIVE, COM_PORT, 0));

  for (int i = 0; buf[i]; i++) {
      printf("Sending byte %i, %i\n", i, _bios_serialcom(_COM_SEND, COM_PORT, buf[i]));
  }

  for (int i = 0; i < 10; i++)
    printf("Waiting: %i\n", _bios_serialcom(_COM_RECEIVE, COM_PORT, 0));
}

void testGDB() {
  gdb_serial_init(1, 9600);
  gdb_target_init();
  breakpoint();
}

int main(int argc, char **argv) {
  testGDB();
  // testCOM();

  return 0;
}