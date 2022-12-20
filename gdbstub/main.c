#include "i386-stub.h"
#include <stdio.h>
#include <stdlib.h>

void setupGDB() {
  gdb_serial_init(1);
  gdb_target_init();
  breakpoint();
}

typedef struct p {
  float x, y, z;
} p;

void setZ(p *point, int z) {
  p *pnt = point;
  pnt->z = z;
}

int main(int argc, char **argv) {
    setupGDB();

    p point = {1, 2, 3};
    int a = 123;
    int b = 2;
    int c = a + b;
    setZ(&point, c);
    printf("WTF");
    return 0;
}