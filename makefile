OBJS = integer.o dll.o test-dll.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : test-dll

test-dll: $(OBJS)
	gcc $(LOPTS) $(OBJS) -o test-dll

integer.o: integer.c integer.h
	gcc $(OOPTS) integer.c

dll.o: dll.c dll.h
	gcc $(OOPTS) dll.c

test-dll.o:	test-dll.c dll.h
	gcc $(OOPTS) test-dll.c

test: test-dll
	./test-dll

valgrind: test-dll
	valgrind test-dll

clean:
	rm -f *.o vgcore.* test-dll
