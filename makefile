ListEntry.o : ListEntry.c ListEntry.h CustomType.h
	gcc -c ListEntry.c 

List.o : List.c List.h ListEntry.o
	gcc -c List.c 

main.o : main.c ListEntry.h List.h CustomType.h
	gcc -c Main.c

test : main.o ListEntry.o List.o
	gcc -o test main.o ListEntry.o List.o
	rm *.o

clean :
	rm test *.o
