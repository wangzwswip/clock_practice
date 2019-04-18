film:films3.o list.o  
	gcc -g -o film films3.o list.o 
films3.o:films3.c list.h
	gcc -g -c films3.c
list.o: list.c list.h 
	gcc -g -c list.c 
clean: 
	rm -rf test 
	rm -rf *.o
