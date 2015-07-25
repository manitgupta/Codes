all: createMaze
	gcc -o driver -pg driver.c createMaze.o
createMaze: createMaze.c MazeOps.h Maze.h
	gcc -c createMaze.c
clean: 
	rm -rf driver
	rm -rf createMaze.o
