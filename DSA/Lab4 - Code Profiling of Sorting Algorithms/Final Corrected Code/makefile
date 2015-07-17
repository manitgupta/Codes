all: merge quick insert
	gcc -o driver -pg driver.c mergesort.o insertionsort.o quicksort.o
merge: mergesort.c mergesort.h
	gcc -c mergesort.c
quick: quicksort.c quicksort.h
	gcc -c quicksort.c
insert: insertionsort.c insertionsort.h
	gcc -c insertionsort.c
clean:
	rm -rf driver
	rm -rf mergesort.o
	rm -rf quicksort.o
	rm -rf	insertionsort.o 