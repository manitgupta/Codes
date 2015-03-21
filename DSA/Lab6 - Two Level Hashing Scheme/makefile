all: htops
	gcc -o query query.c htops.o
htops: htops.c htops.h hashtable.h
	gcc -c htops.c
clear:
	rm -rf query
	rm -rf htops.o