#include <stdio.h>
#include <stdlib.h>


//#define DEBUG
/*la opcion de debug se puede hacer desde el compilador  solo se debe hacer:
 gcc ...... -DDEBUG

La opcion -D define lo siguiente como parte de la compilcion
  */

#define SIZE_PUZZLE 9
#define TRUE 1
#define FALSE 0
#define RESULT ['1','2','3','4','5','6','7','8','X']

/* el puzzle sera representado por una lista de enteros donde el largo de esta
es de 9 elementos siempre:

puzzle = [1,2,3,4,5,6,7,8,X]  =   1  2  3 , matriz de posicion = 0 1 2
                                  4  5  6                        3 4 5
                                  7  8  X                        6 7 8

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
typedef struct nodo {
  char* puzzle;
  int movimientos;
  struct nodo* next;
}puzzle8;


typedef struct {
  puzzle8* first;
  int count;
}cola;


char result[9]={'1','2','3','4','5','6','7','8','X'};

/*lectura de archivo, el archivo debe tener un formato de puzzle de la siguiente manera:

				  1  2  3
                                  4  5  6
                                  7  8  X

*/

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
  tablero->next =NULL;
  return tablero;

}

//funcion para obtener la posicion de X

int currentPositionX(puzzle8* P){

  for(int i =0; i<SIZE_PUZZLE;i++){
    if(P->puzzle[i] == 'X'){
	return i;
    }
  }
  return -1;
}




/* ################## Funciones de Comprobacion ################## */


/* ¿X se puede mover hacia arriba? se podra mover si no esta en
 las posiciones [0,1,2] o si:

   sea i = posicion de 'X' en el arreglo
   Si i-3 >= 0
*/

int canXUp(puzzle8* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX -3) >= 0){
    return TRUE;
  }
  else{

    return FALSE;
  }

}

void moveXUp(puzzle8* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->puzzle[currentX-3];
  puzzle->puzzle[currentX] = aux;
  puzzle->puzzle[currentX-3] = 'X';

}



/* ¿X se puede mover hacia abajo? se podra mover si no esta en
 las posiciones [6,7,8] o si:

   sea i = posicion de 'X' en el arreglo
   Si i+3 <= 8
*/


int canXDown(puzzle8* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX + 3) <= 8){
    return TRUE;
  }
  else{

    return FALSE;
  }

}


void moveXdown(puzzle8* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->puzzle[currentX+3];
  puzzle->puzzle[currentX] = aux;
  puzzle->puzzle[currentX+3] = 'X';

}

/* ¿X se puede mover hacia la derecha? se podra mover si no esta en
 las posiciones [2,5,8] o si:

   sea i = posicion de 'X' en el arreglo
   Si (i+1) % 3 != 0
*/


int canXrigth(puzzle8* puzzle){

  int currentX = currentPositionX(puzzle);
  if(((currentX + 1) % 3) != 0){
    return TRUE;
  }
  else{

    return FALSE;
  }

}

void moveXrigth(puzzle8* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->puzzle[currentX+1];
  puzzle->puzzle[currentX] = aux;
  puzzle->puzzle[currentX+1] = 'X';

}

/* ¿X se puede mover hacia la izquierda? se podra mover si no esta en
 las posiciones [0,3,6] o si:

   sea i = posicion de 'X' en el arreglo
   Si i % 3 != 0
*/

int canXleft(puzzle8* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX % 3) != 0){
    return TRUE;
  }
  else{

    return FALSE;
  }

}

void moveXleft(puzzle8* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->puzzle[currentX-1];
  puzzle->puzzle[currentX] = aux;
  puzzle->puzzle[currentX-1] = 'X';

}

/* ################## Funciones de colas ################## */

//queue
void encolar(cola* currentC, puzzle8* new){

  if (currentC->first == NULL) {
    currentC->first = new;
    currentC->count = 1;

    #ifdef DEBUG

     printf("***La cola no tiene elementos = Cola vacia***\n");

    #endif

  }
  else{

    #ifdef DEBUG

     printf("***La cola tiene elementos = Cola NO vacia***\n");

    #endif
    puzzle8* aux = currentC->first;

    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new;
    currentC->count++;

  }

}

//dequeue
puzzle8* desencolar(cola* currentC){

  if (currentC->first == NULL) {

    #ifdef DEBUG
    printf("No hay nada que desencolar\n");
    #endif
    return NULL;
  }
  else{

    #ifdef DEBUG
    printf("hay elementos que desencolar\n");
    #endif
    puzzle8* aux = currentC->first;
    currentC->first=currentC->first->next;
    aux->next=NULL;
    currentC->count--;
    return aux;
  }
}

/* Funcion booleana que detecta si una estructura puzzle8 contiene el mismo
arreglo que otra estructura */

int equalsPuzzle(puzzle8* pzl, puzzle8* pzl2){

  for (int i = 0; i < SIZE_PUZZLE; i++) {
    if (pzl->puzzle[i] != pzl2->puzzle[i]) {
      return FALSE;
    }
  }
  return TRUE;
}

/* funcion booleana que detecta si dentro de toda la cola existe un puzzle
igual a otro */

int puzzleInCola(cola* currentC, puzzle8* pzl){

  puzzle8* aux = currentC->first;

  while(aux != NULL){

    if (equalsPuzzle(aux, pzl) == TRUE) {
       return TRUE;
    }
    aux = aux->next;
  }
  return FALSE;
}



void imprimir(puzzle8* pzl){
  int y = 0;
  for (int i = 0; i < SIZE_PUZZLE; i++) {
    if (y == 3) {
      printf("\n" );
      y=0;
    }
    printf("%c ",pzl->puzzle[i]);
    y++;
  }
  printf("\n");

}
int main(int argc, char const *argv[]) {

  #ifdef DEBUG //Sentencia de DEBUG

  puzzle8* a = readFile("puzzle.txt");
  cola* visitados = (cola*)malloc(sizeof(cola));
  visitados->first = NULL;
  visitados->count = 0;
  encolar(visitados,a);
  printf("**********************\n");
  int x = 0;
  while (x <= 5) {


  imprimir(a);

  printf("comenzando a mover...\n" );
  if(canXUp(a) == TRUE){
    moveXUp(a);
    imprimir(a);
  }
  if(canXDown(a) == TRUE){

    printf("se puede mover hacia abajo\n");

    moveXdown(a);
    imprimir(a);
  }
  if(canXleft(a) == TRUE){

    printf("se puede mover hacia la izquierda\n");
    moveXleft(a);
    imprimir(a);
  }
  if(canXrigth(a) == TRUE){

    printf("se puede mover hacia la derecha\n");
    moveXrigth(a);
    imprimir(a);
  }

  x++;

}
free(a);

  #endif
  return 0;
}
