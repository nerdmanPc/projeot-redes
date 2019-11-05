interface: interface.c
	gcc -o main interface.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -rdynamic
