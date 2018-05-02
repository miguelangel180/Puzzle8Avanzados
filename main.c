#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"
#include "tools.h"
#include "result.h"
#include "visit.h"
#include "IOPuzzle.h"


/*en caso de que se active el modo DEBUG se entrara al modo debug
el cual mostrata el paso a paso de las funciones.
*/

int main(int argc, char const *argv[]) {

  #ifdef DEBUG
  printf("¡¡¡¡ MODO DEBUG ACTIVADO !!!! \n");
  printf("*******************************\n");
  #endif
  //iniciando
  puzzle* actual = readFile("puzzle.txt");
  list* cola_actual = (list*)malloc(sizeof(list));
  cola_actual->first = NULL;
  cola_actual->count = 0;
  visit* visitados =  (visit*)malloc(sizeof(visit));
  visitados->count=0;
  result* resultados = (result*)malloc(sizeof(result));
  resultados->count=0;

  //se encola el primer puzzle leido del archivo
  encolar(cola_actual,actual);
  //se llama a la funcion iterativa -> se genera una lista de visitados
  //se genera una lista de resultados
  iterativo(cola_actual,visitados,resultados);
  //se obtiene el minimo movimiento de la lista de resultados
  int moves = getMinMoves(resultados);
  #ifdef DEBUG
  printf("la cantidad minima para resolver el puzzle es : %i\n",moves);
  printf("la cantidad de puzzles visitados es : %i\n",getCountVisit(visitados));
  #endif
  printf("********************************\n");
  printf("* Programa terminado con exito *\n");
  printf("********************************\n");
  printf("\n\n\n");
  printf("* Revisar archivo de salida -> 'salida.txt' *\n");

  //se liberan ambas listas (visitados y resultados)
  freeVisit(visitados);
  freeResult(resultados);

  //se escribe sobre el archivo "salida.txt"
  writeFile(moves);

  return 0;
}
