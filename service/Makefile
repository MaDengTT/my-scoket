service_run : wrap.o service_t.o
	gcc wrap.o service_t.o
wrap.o : wrap.h wrap.c
	gcc -c wrap.c
service_t.o: service_t.c wrap.c
	gcc -lpthread -c service_t.c 