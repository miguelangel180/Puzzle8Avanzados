puzzle8: main.o visit.o tools.o result.o Puzzle.o IOPuzzle.o
	gcc -Wall -DDEBUG -o puzzle8 main.o visit.o tools.o result.o Puzzle.o IOPuzzle.o

main.o: main.c structs.h IOPuzzle.h tools.h result.h visit.h
	gcc -c -g -DDEBUG -Wall main.c

visit.o: visit.c structs.h visit.h
	gcc -Wall -g -DDEBUG -c visit.c

tools.o: tools.c tools.h Puzzle.h visit.h result.h structs.h
	gcc -Wall -g -DDEBUG -c tools.c

result.o: result.c structs.h result.h
	gcc -Wall -g -DDEBUG -c result.c

Puzzle.o: Puzzle.c structs.h Puzzle.h
	gcc -Wall -g -DDEBUG -c Puzzle.c

IOPuzzle.o: IOPuzzle.c structs.h IOPuzzle.h
	gcc -Wall -g -DDEBUG -c IOPuzzle.c
#limpiador de archivos temporales
#limpiado para linux
cleanL:
	rm -f buscador *.o
#limpiador para windows	
cleanW:
	del puzzle8.exe *.o
