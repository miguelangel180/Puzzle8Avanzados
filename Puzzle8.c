#include <stdio.h>
#include <stdlib.h>


//#define DEBUG
/*la opcion de debug se puede hacer desde el compilador  solo se debe hacer:
 gcc ...... -DDEBUG

La opcion -D define lo siguiente como parte de la compilcion
  */

#define SIZE_PUZZLE 9


/* el puzzle sera representado por una lista de enteros donde el largo de esta
es de 9 elementos siempre:

puzzle = [1,2,3,4,5,6,7,8,X]  =   1  2  3
                                  4  5  6
                                  7  8  X
Para obtener un elemento de este puzzle es necesario una coordenada (X,Y)
ya que :

    Elemento = Y*N + X  //donde N es el tamaño de la matriz, para este caso
    N es 3 (debido a que la matriz es de 3x3)

    Finalmente para obtener un elemento en (X,Y) sera:

    Elemento = Y*3+X

    la restriccion para X es I= [0,2] o X <= 2 y X >= 0
    la restriccion para Y es I= [0,2] o Y <= 2 y Y >= 0
*/

// esta estructura representa un estado i del puzzle
typedef struct {
  char* puzzle;
  int movimientos;
}puzzle8;

//lectura de archivo
puzzle8* readFile(char* rute){
  char* puzzleList = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
  FILE* fichero = fopen(rute,"r");


#ifdef DEBUG //Sentencia de DEBUG
  if (fichero) {
    printf("Fichero abierto correctamente\n");
  }
  else
   {
    printf("No se pudo abrir el archivo\n");
  }
#endif

  int i = 0;
  while (!feof(fichero)){
    fscanf(fichero,"%c",&puzzleList[i]);
    if (puzzleList[i]!= ' ' && puzzleList[i]!= '\n') {
       i++;
    }

  }
  #ifdef DEBUG //Sentencia de DEBUG
  for (i = 0; i < SIZE_PUZZLE; i++) {
    printf(" posicion %i , caracter: %c\n",i,puzzleList[i]);
  }
  #endif

  puzzle8* tablero = (puzzle8*)malloc(sizeof(puzzle8));
  tablero->puzzle = puzzleList;
  tablero->movimientos = 0;
  return tablero;

}

int main(int argc, char const *argv[]) {
  puzzle8* a = readFile("puzzle.txt");
  printf("nuevo**********************\n");
  for (int i = 0; i < SIZE_PUZZLE; i++) {
    printf(" posicion %i , caracter: %c\n",i,a->puzzle[i]);
  }
  return 0;
}
