OBJS0 = dll-0-0.o integer.o dll.o
OBJS1 = dll-0-1.o real.o dll.o
OBJS2 = dll-0-2.o string.o dll.o
OBJS3 = dll-0-3.o integer.o dll.o
OBJS4 = dll-0-4.o integer.o dll.o
OBJS5 = dll-0-5.o real.o dll.o
OBJS6 = dll-0-6.o real.o dll.o
OBJS7 = dll-0-7.o integer.o dll.o
OBJS8 = dll-0-8.o dll.o
OBJS9 = dll-0-9.o integer.o dll.o
OBJS10 = dll-0-10.o integer.o dll.o
OBJS11 = dll-0-11.o real.o dll.o
OBJS12 = dll-0-12.o real.o dll.o
OBJS13 = dll-0-13.o integer.o dll.o
OBJS14 = dll-0-14.o integer.o dll.o
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all : dll-0-0 dll-0-1 dll-0-2 dll-0-3 dll-0-4 dll-0-5 dll-0-6 dll-0-7 dll-0-8 \
		dll-0-9 dll-0-10 dll-0-11 dll-0-12 dll-0-13 dll-0-14

dll-0-0: $(OBJS0)
	gcc $(LOPTS) $(OBJS0) -o dll-0-0

dll-0-1: $(OBJS1)
	gcc $(LOPTS) $(OBJS1) -o dll-0-1

dll-0-2: $(OBJS2)
	gcc $(LOPTS) $(OBJS2) -o dll-0-2

dll-0-3: $(OBJS3)
	gcc $(LOPTS) $(OBJS3) -o dll-0-3

dll-0-4: $(OBJS4)
	gcc $(LOPTS) $(OBJS4) -o dll-0-4

dll-0-5: $(OBJS5)
	gcc $(LOPTS) $(OBJS5) -o dll-0-5

dll-0-6: $(OBJS6)
	gcc $(LOPTS) $(OBJS6) -o dll-0-6

dll-0-7: $(OBJS7)
	gcc $(LOPTS) $(OBJS7) -o dll-0-7

dll-0-8: $(OBJS8)
	gcc $(LOPTS) $(OBJS8) -o dll-0-8

dll-0-9: $(OBJS9)
	gcc $(LOPTS) $(OBJS9) -o dll-0-9

dll-0-10: $(OBJS10)
	gcc $(LOPTS) $(OBJS10) -o dll-0-10

dll-0-11: $(OBJS11)
	gcc $(LOPTS) $(OBJS11) -o dll-0-11

dll-0-12: $(OBJS12)
	gcc $(LOPTS) $(OBJS12) -o dll-0-12

dll-0-13: $(OBJS13)
	gcc $(LOPTS) $(OBJS13) -o dll-0-13

dll-0-14: $(OBJS14)
	gcc $(LOPTS) $(OBJS14) -o dll-0-14

dll.o: dll.c dll.h
	gcc $(OOPTS) dll.c

dll-0-0.o:	./testing/dll-0-0.c dll.h
	gcc $(OOPTS) ./testing/dll-0-0.c

dll-0-1.o:	./testing/dll-0-1.c dll.h
	gcc $(OOPTS) ./testing/dll-0-1.c

dll-0-2.o:	./testing/dll-0-2.c dll.h
	gcc $(OOPTS) ./testing/dll-0-2.c

dll-0-3.o:	./testing/dll-0-3.c dll.h
	gcc $(OOPTS) ./testing/dll-0-3.c

dll-0-4.o:	./testing/dll-0-4.c dll.h
	gcc $(OOPTS) ./testing/dll-0-4.c

dll-0-5.o:	./testing/dll-0-5.c dll.h
	gcc $(OOPTS) ./testing/dll-0-5.c

dll-0-6.o:	./testing/dll-0-6.c dll.h
	gcc $(OOPTS) ./testing/dll-0-6.c

dll-0-7.o:	./testing/dll-0-7.c dll.h
	gcc $(OOPTS) ./testing/dll-0-7.c

dll-0-8.o:	./testing/dll-0-8.c dll.h
	gcc $(OOPTS) ./testing/dll-0-8.c

dll-0-9.o:	./testing/dll-0-9.c dll.h
	gcc $(OOPTS) ./testing/dll-0-9.c

dll-0-10.o:	./testing/dll-0-10.c dll.h
	gcc $(OOPTS) ./testing/dll-0-10.c

dll-0-11.o:	./testing/dll-0-11.c dll.h
	gcc $(OOPTS) ./testing/dll-0-11.c

dll-0-12.o:	./testing/dll-0-12.c dll.h
	gcc $(OOPTS) ./testing/dll-0-12.c

dll-0-13.o:	./testing/dll-0-13.c dll.h
	gcc $(OOPTS) ./testing/dll-0-13.c

dll-0-14.o:	./testing/dll-0-14.c dll.h
	gcc $(OOPTS) ./testing/dll-0-14.c

integer.o: integer.c integer.h
	gcc $(OOPTS) integer.c

real.o: real.c real.h
	gcc $(OOPTS) real.c

string.o: string.c string.h
	gcc $(OOPTS) string.c


test: all 
	echo Testing Doubly-Linked List 
	@echo Running dll-0-0 tester...
	@./dll-0-0 > ./testing/myResults/results-0-0
	@diff ./testing/expectedResults/results-0-0 ./testing/myResults/results-0-0
	@echo
	@echo Running dll-0-1 tester...
	@./dll-0-1 > ./testing/myResults/results-0-1
	@diff ./testing/expectedResults/results-0-1 ./testing/myResults/results-0-1
	@echo
	@echo Running dll-0-2 tester...
	@./dll-0-2 > ./testing/myResults/results-0-2
	@diff ./testing/expectedResults/results-0-2 ./testing/myResults/results-0-2
	@echo
	@echo Running dll-0-3 tester...
	@./dll-0-3 > ./testing/myResults/results-0-3
	@diff ./testing/expectedResults/results-0-3 ./testing/myResults/results-0-3
	@echo
	@echo Running dll-0-4 tester...
	@./dll-0-4 > ./testing/myResults/results-0-4
	@diff ./testing/expectedResults/results-0-4 ./testing/myResults/results-0-4
	@echo
	@echo Running dll-0-5 tester...
	@./dll-0-5 > ./testing/myResults/results-0-5
	@diff ./testing/expectedResults/results-0-5 ./testing/myResults/results-0-5
	@echo
	@echo Running dll-0-6 tester...
	@./dll-0-6 > ./testing/myResults/results-0-6
	@diff ./testing/expectedResults/results-0-6 ./testing/myResults/results-0-6
	@echo
	@echo Running dll-0-7 tester...
	@./dll-0-7 > ./testing/myResults/results-0-7
	@diff ./testing/expectedResults/results-0-7 ./testing/myResults/results-0-7
	@echo
	@echo Running dll-0-8 tester...
	@./dll-0-8 > ./testing/myResults/results-0-8
	@diff ./testing/expectedResults/results-0-8 ./testing/myResults/results-0-8
	@echo
	@echo Running dll-0-9 tester...
	@./dll-0-9 > ./testing/myResults/results-0-9
	@diff ./testing/expectedResults/results-0-9 ./testing/myResults/results-0-9
	@echo
	@echo Running dll-0-10 tester...
	@./dll-0-10 > ./testing/myResults/results-0-10
	@diff ./testing/expectedResults/results-0-10 ./testing/myResults/results-0-10
	@echo
	@echo Running dll-0-11 tester...
	@./dll-0-11 > ./testing/myResults/results-0-11
	@diff ./testing/expectedResults/results-0-11 ./testing/myResults/results-0-11
	@echo
	@echo Running dll-0-12 tester...
	@./dll-0-12 > ./testing/myResults/results-0-12
	@diff ./testing/expectedResults/results-0-12 ./testing/myResults/results-0-12
	@echo
	@echo Running dll-0-13 tester...
	@./dll-0-13 > ./testing/myResults/results-0-13
	@diff ./testing/expectedResults/results-0-13 ./testing/myResults/results-0-13
	@echo
	@echo Running dll-0-14 tester...
	@./dll-0-14 > ./testing/myResults/results-0-14
	@diff ./testing/expectedResults/results-0-14 ./testing/myResults/results-0-14

valgrind: all 
	valgrind dll-0-0
	valgrind dll-0-1
	valgrind dll-0-2
	valgrind dll-0-3
	valgrind dll-0-4
	valgrind dll-0-5
	valgrind dll-0-6
	valgrind dll-0-7
	valgrind dll-0-8
	valgrind dll-0-9
	valgrind dll-0-10
	valgrind dll-0-11
	valgrind dll-0-12
	valgrind dll-0-13
	valgrind dll-0-14

clean:
	rm -f *.o vgcore.* dll-0-0 dll-0-1 dll-0-2 dll-0-3 dll-0-4 dll-0-5 dll-0-6 \
	dll-0-7 dll-0-8 dll-0-9 dll-0-10 dll-0-11 dll-0-12 dll-0-13 dll-0-14
