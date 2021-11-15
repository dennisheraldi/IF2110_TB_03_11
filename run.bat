@echo off
title Mobilita

gcc *.c ADT/*.c lib/BUY/*.c lib/commandParser/*.c lib/DROP_OFF/*.c lib/MAP/*.c lib/MOVE/*.c lib/PICK_UP/*.c lib/string/*.c lib/TO_DO/*.c config/*.c -o bin -lm -fno-stack-protector
bin

pause