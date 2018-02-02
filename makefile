OBJS = integer.o dll.o dll-0-14.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : dll-0-14

dll-0-14: $(OBJS)
	gcc $(LOPTS) $(OBJS) -o dll-0-14

integer.o: integer.c integer.h
	gcc $(OOPTS) integer.c

dll.o: dll.c dll.h
	gcc $(OOPTS) dll.c

dll-0-14.o:	./testing/dll-0-14.c dll.h
	gcc $(OOPTS) ./testing/dll-0-14.c

test: dll-0-14
	./dll-0-14

valgrind: dll-0-14
	valgrind dll-0-14

clean:
	rm -f *.o vgcore.* dll-0-14
