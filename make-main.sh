#!/bin/sh
set -e
~/workspaces/djgpp-12/bin/i586-pc-msdosdjgpp-gcc -DDEBUG -gdwarf-2 -Igdbstub/ gdbstub/i386-stub.c gdbstub/i386-supp.c gdbstub/main.c -o main.exe