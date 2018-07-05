CC=gcc
OBJ = happychat_server
all:
	$(CC)  -o  $(OBJ)    *.cpp   -lpthread  -I/usr/include/mysql/ -L/usr/lib/mysql -lmysqlclient `pkg-config  --libs --cflags gtk+-2.0`  -g
 
clean:
	-rm -rf *.o