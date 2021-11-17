@echo off
title Mobilita

gcc *.c ADT/BANGUNAN/*.h ADT/BARANG/*barang.c ADT/*.h ADT/CHARMACHINE/*charmachine.c ADT/GARIS/garis.c ADT/LIST/list.c ADT/LIST_LINKED/list_linked.c ADT/LIST_LINKED/node.c ADT/LISTDIN/listdin.c ADT/MATRIX/matrix.c ADT/PCOLOR/pcolor.c ADT/POINT/point.c ADT/PRIOQUEUE/prioqueue.c ADT/QUEUE/queue.c ADT/STACK/stack.c ADT/TIME/time.c ADT/TOKENMACHINE/tokenmachine.c ADT/VECTOR/vector.c ADT/WORDMACHINE/wordmachine.c lib/BUY/*.c lib/COMMAND_PARSER/*.c lib/DROP_OFF/*.c lib/MAP/*.c lib/MOVE/*.c lib/PICK_UP/*.c lib/STRING_PROCESSOR/*.c lib/TO_DO/*.c config/*.c lib/HELP/*.c lib/INVENTORY/*.c lib/IN_PROGRESS/*.c lib/RETURN/*.c -o bin -lm -fno-stack-protector 

bin

pause