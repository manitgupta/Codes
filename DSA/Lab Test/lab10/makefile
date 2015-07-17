all: llist.o stack.o queue.o graph.o driver.c
	gcc -o driver driver.c graph.o stack.o queue.o llist.o

graph.o: stack.o queue.o graph.c graph.h
	gcc -c graph.c

stack.o: llist.o stack.h stack.c
	gcc -c stack.c

queue.o: llist.o queue.h queue.c
	gcc -c queue.c

llist.o: llist.c llist.h
	gcc -c llist.c

clean:
	rm -rf graph.o
	rm -rf stack.o
	rm -rf queue.o
	rm -rf llist.o