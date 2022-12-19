#!/bin/sh
set -e
~/workspaces/djgpp/bin/i586-pc-msdosdjgpp-gcc -g -Igdbstub/ gdbstub/i386-stub.c gdbstub/i386-supp.c gdbstub/main.c -o main.exe